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
vector<pii> v[333];

int d[333];

int best=-1;
int bd[333];

void solve(int root){
	REP(i,n)d[i]=-1000;
	d[root]=0;
	priority_queue<pii> q;
	q.push(pii(d[root],root));
	while(!q.empty()){
		pii c = q.top();q.pop();
		int ver = c.second;
		int val = c.first;
		if(val>0)return;
		if(d[ver]!=val)continue;

		//cout<<ver<<": "<<val<<endl;

		REP(i,v[ver].size()){
			int nver = v[ver][i].first;
			if(v[ver][i].second==1){
				if(d[nver]==d[ver]+1)continue;
				if(d[nver]>d[ver]+1)return;
				d[nver]=d[ver]+1;
				q.push(pii(d[nver],nver));
			}else if(v[ver][i].second==-1){
				if(d[nver]==d[ver]-1)continue;
				if(d[nver]>d[ver]-1)return;
				d[nver]=d[ver]-1;
				q.push(pii(d[nver],nver));
			}else{
				int nd = max(d[nver],d[ver]-1);
				if(d[nver]==nd)continue;
				d[nver]=nd;
				q.push(pii(d[nver],nver));
			}
		}
	}

	// check
	REP(i,n)REP(j,v[i].size()){
		int dd = d[i] - d[v[i][j].first];
		if(abs(dd)!=1)return;
		if(v[i][j].second==1 && dd !=-1) return;
		if(v[i][j].second==-1 && dd != 1)return;
	}

	int mn = d[0];
	int mx = d[0];
	REP(i,n)mn=min(mn,d[i]);
	REP(i,n)mx=max(mx,d[i]);

	if(best==-1 || best<mx-mn){
		best=mx-mn;
		REP(i,333)bd[i]=d[i];
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v[x].pb(pii(y,-z));
		v[y].pb(pii(x,z));
	}
	REP(i,n)solve(i);
	//solve(5);
	if(best==-1)puts("NO");
	else{
		puts("YES");
		cout<<best<<endl;
		REP(i,n){
			printf("%d ",-bd[i]+1000);
		}
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}