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
#include<unordered_map>
#include<unordered_set>

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

int n,m;
vector<pl> v[111111];
ll        xr[111111];
bool      u[111111];
bool act[111111];

vi c;
vector<ll> cc;

void dfs(int ver,ll XR=0,int par=-1){
	if(u[ver])return;
	u[ver]=true;
	act[ver]=true;
	c.pb(ver);
	xr[ver]=XR;
	REP(i,v[ver].size()){
		int nv = v[ver][i].first;
		if(!u[nv]){
			dfs(nv,XR^v[ver][i].second,ver);
		}else{
			if(par!=nv && act[nv]){
				cc.pb(xr[ver]^xr[nv]^v[ver][i].second);
			}
		}
	}
	act[ver]=false;
}

void simplify(){
	int rows = 0;
	REP(i,62){
		int pos=-1;
		FOR(j,rows,cc.size())if(cc[j]&(1ll<<i)){
			pos=j;
			break;
		}
		if(pos==-1)continue;
		swap(cc[rows],cc[pos]);
		REP(j,cc.size())if(j!=rows){
			if(cc[j]&(1ll<<i))cc[j]^=cc[rows];	
		}
		rows++;
	}
	cc.resize(rows);
}

ll tmask;

ll solve(){
	vector<ll> w;
	ll sum=0;
	REP(i,c.size())w.pb(xr[c[i]]&(~(tmask)));
	REP(i,62){
		int has=0;
		REP(j,w.size())if(w[j]&(1ll<<i))has++;
		int nhas = w.size() - has;

		sum = (sum + has * ll(nhas) % mod * ((1ll<<i)%mod)) % mod;
	}
	return sum;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		ll z;
		scanf("%d %d %I64d",&x,&y,&z);
		x--,y--;
		v[x].pb(pl(y,z));
		v[y].pb(pl(x,z));
	}

	ll res  = 0;

	REP(i,n)if(!u[i]){
		c.clear();
		cc.clear();
		dfs(i);
		tmask=0;
		REP(j,cc.size())tmask|=cc[j];
		simplify();

		ll num = c.size();
		ll cnt = num * (num-1)/2 %mod;
		if (!cc.empty())	res = (res + cnt   * (tmask % mod) % mod * ((1ll << (cc.size()-1))%mod)) % mod;

		ll t = solve();
		res = (res + t * ((1ll<<cc.size())%mod))%mod;
		//cout<<"="<<res<<endl;
	}

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}