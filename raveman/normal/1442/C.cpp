//#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
vi v[222222];
vi vt[222222]; 

pii d[222222][2][21];

bool better(pii c1,pii c2){
	if(c2.first==1)return 1;
	int p1 = -c1.first;
	int v1 = -c1.second;
	int p2 = -c2.first;
	int v2 = -c2.second;

	if(p1==p2)return v1<v2;

	if(p1<20 && p2<20){
		return (1<<p1)+v1  < (1<<p2)+v2;
	}else{
		return p1<p2;	
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		vt[y].pb(x);
	}
	REP(i,n)REP(t,2)REP(t2,21)d[i][t][t2]=pii(1,1);
	d[0][0][0]=pii(0,0);
	//cout<<v[1].size()<<' '<<vt[1].size()<<endl;
	priority_queue< pair<pii,int> > q;
	q.push(make_pair(pii(-0,-0),0*50*2+0*50+0));
	pii bst(1,1);
	while(!q.empty()){
		int tmp = q.top().second;
		pii val = q.top().first;
		q.pop();
		int ver = tmp/100;
		if(ver == n-1 && better(val,bst))bst=val;
		int type = (tmp/50)%2;
		int nm = tmp%50;
		if(better(d[ver][type][nm],val))continue;

		//cout<<ver<<' '<<type<<' '<<nm<<' '<<val.first<<' '<<val.second<<endl;

		// edge
		vi& x = (type==0?v:vt)[ver];
		REP(i,x.size()){
			int nv = x[i];
			//cout<<"test "<<nv<<endl;
			pii ncost = val;
			ncost.second--;
			if(better(ncost,d[nv][type][nm])){
				d[nv][type][nm]=ncost;
				q.push(make_pair(ncost,nv*100+type*50+nm));
			}
		}
		// flip
		pii ncost = val;
		ncost.first--;
		if(better(ncost,d[ver][1-type][min(nm+1,20)])){
			d[ver][1-type][min(nm+1,20)]=ncost;
			q.push(make_pair(ncost,ver*100+(1-type)*50+min(nm+1,20)));
		}
	}

	const int mod = 998244353;
	ll res = -bst.second;
	ll c = 1;
	for(int i=1;i<=-bst.first;i++){
		res=(res+c)%mod;
		c*=2;
		c%=mod;
	}
	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}