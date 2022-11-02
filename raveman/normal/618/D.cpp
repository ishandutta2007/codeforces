#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,x,y;
vi v[222222];

int r[222222][2];

int dfs(int ver, int type, int par=-1){
	if(r[ver][type]!=-1)return r[ver][type];
	int res = 0;
	vi v0,v1;
	int sum0=0;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		v0.pb(dfs(v[ver][i],0,ver));
		v1.pb(dfs(v[ver][i],1,ver));
		sum0 += v0.back();
	}

	res=sum0;

	REP(i,v0.size()){
		res = max(res, 1 + v1[i] + sum0 - v0[i]);
	}

	if (type==0){
		vi d;
		REP(i,v0.size()) d.pb(v1[i]-v0[i]);
		sort(d.rbegin(),d.rend());
		if(d.size()>=2){
			res=max(res, 2 +sum0+ d[0]+d[1]);
		}
	}

	return r[ver][type]=res;
}

int solve(){
	CL(r,-1);
	return dfs(0,0);
}

int edgecost(int a,int b){
	REP(i,v[a].size())
		if(v[a][i]==b) return x;
	return y;
}

ll stupid(){
		vi p(n);
		REP(i,n)p[i]=i;
		ll best = 1e18;
		do{
			ll sum = 0;
			FOR(i,1,n){
				sum += edgecost(p[i],p[i-1]);
			}
			best=min(best,sum);
		}while(next_permutation(p.begin(),p.end()));
		return best;
}

bool DEBUG=0;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

start:
	if(DEBUG){
		n=rand()%6+2;
		x=rand()%10+1;
		y=rand()%10+1;
		REP(i,n)v[i].clear();
	}
	if(!DEBUG)cin>>n>>x>>y;
	REP(i,n-1){
		int xx,yy;
		if(!DEBUG) scanf("%d %d",&xx,&yy);
		else{
			yy=i+2;
			xx=rand()%(i+1)+1;
		}
		xx--,yy--;
		v[xx].pb(yy);
		v[yy].pb(xx);
	}

	ll res;

	if (x == y) res=ll(x) * (n-1);
	else if(n<=4)res=stupid();
	else{
		if(x>y){
			res = ll(y)*(n-1);
			REP(i,n)if(v[i].size()==n-1){
				res = ll(y)*(n-2)+x;
				break;
			}
		}else{
			int mx = solve();
			res = mx*ll(x)+ll(n-1-mx)*y;
		}
	}
	cout<<res<<endl;

	if(DEBUG){
		if(res != stupid()) {
			cout<<n<<' '<<x<<' '<<y<<endl;
			REP(i,n)REP(j,v[i].size()){
				cout<<i+1<<' '<<v[i][j]+1<<endl;
			}
			puts("FOUND!");
			cout<<res<<' '<<stupid()<<endl;
		}
		else goto start;
	}
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}