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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

int n;
int a[111111],b[111111];
bool u[222222];
int v[222222];
vi rev[222222];
int f[222222];
int o[222222];

ll solve(int ver){
	ll num = 1;
	REP(i,rev[ver].size()){
		ll t = solve(rev[ver][i]);
		num += t;
		if (num>=mod)num-=mod;
	}
	return num;
}

int now;
ll dfs(int ver){
	now++;
	int len = 1;
	while(!v[ver]){
		o[ver]=len;
		v[ver]=now;
		ver=f[ver];
		len++;
	}
	if(v[ver]==now){
		return min(2,len - o[ver]);
	}
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		scanf("%d %d",a+i,b+i);
		u[a[i]]=1;
		f[a[i]]=b[i];
		rev[b[i]].pb(a[i]);
	}

	ll res = 1;
	REP(i,222222)if(!u[i]&&!rev[i].empty()){
		res *= solve(i);
		res %= mod;
	}
	REP(i,222222)if(u[i]&&!v[i]){
		res*=dfs(i);
		res%=mod;
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}