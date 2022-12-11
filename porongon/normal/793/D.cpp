#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

#define INF (1<<22)

int dp[128][128][128];
vii g[128];
int n,k,m;

int f(int s, int e, int k){
	if(dp[s][e][k]>=0)return dp[s][e][k];
	if(k==0)return dp[s][e][k]=0;
	if(s==e)return dp[s][e][k]=INF;
	int r=INF;
	if(s<e){
		for(auto p:g[s]){
			if(p.fst>s&&p.fst<=e)r=min(r,p.snd+min(f(p.fst,s+1,k-1),f(p.fst,e,k-1)));
		}
	}
	else {
		for(auto p:g[s]){
			if(p.fst>=e&&p.fst<s)r=min(r,p.snd+min(f(p.fst,s-1,k-1),f(p.fst,e,k-1)));
		}
	}
	return dp[s][e][k]=r;
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	FORN(i,m){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);u--;v--;
		g[u].pb(mp(v,c));
	}
	memset(dp,-1,sizeof(dp));
	int r=INF;
	FORN(i,n)r=min(r,f(i,0,k-1)),r=min(r,f(i,n-1,k-1));
	if(r==INF)puts("-1");
	else printf("%d\n",r);
	return 0;
}

/*
  _____   ____  _____   ____  _   _  _____  ____  _   _
 |  __ \ / __ \|  __ \ / __ \| \ | |/ ____|/ __ \| \ | |
 | |__) | |  | | |__) | |  | |  \| | |  __| |  | |  \| |
 |  ___/| |  | |  _  /| |  | | . ` | | |_ | |  | | . ` |
 | |    | |__| | | \ \| |__| | |\  | |__| | |__| | |\  |
 |_|     \____/|_|  \_\\____/|_| \_|\_____|\____/|_| \_|

*/