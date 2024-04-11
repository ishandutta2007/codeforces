//#pragma comment(linker, "/STACK:60777216")  

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

ll p25[111111];
ll p26[111111];
ll    f[111111];
ll invf[111111];

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

map<int,int> mp;
vector<vi> ans;

char s[111111];

void solve(int n){
	if(mp.count(n)) return;
	int sz = mp.size();
	mp[n] = sz;
	ans.pb(vi(100001,0));

	for(int i=n;i<=100000;i++){
		ans.back()[i] = (ans.back()[i-1]*26ll + p25[i-n]*f[i-1]%mod*invf[n-1]%mod*invf[i-n])%mod;
	}
}




int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	p25[0]=1;
	p26[0]=1;
	f[0]=1;
	FOR(i,1,111111){
		p25[i]=p25[i-1]*25%mod;
		p26[i]=p26[i-1]*26%mod;
		f[i]=f[i-1]*i%mod;
	}
	REP(i,111111)invf[i]=qp(f[i],mod-2);

	int m;
	cin>>m;
	scanf(" %s",s);
	int n = strlen(s);
	solve(n);
	int t;
	REP(i,m){
		scanf("%d",&t);
		if(t==1){
			scanf(" %s",s);
			n=strlen(s);
			solve(n);
		}else{
			scanf("%d",&t);
			printf("%d\n",ans[mp[n]][t]);
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}