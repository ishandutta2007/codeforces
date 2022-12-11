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
#define S 317
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int n,m;
int x[100005];
vi g[100005];
int c[100005];
int w[318][100001];

int main(){
	scanf("%d%d",&n,&m);
	memset(x,-1,sizeof(x));
	FORN(i,m){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);x[b]=a;
	}
	FORN(i,n)sort(g[i].begin(),g[i].end());
	for(int k=0;k*S<n;++k){
		w[k][k*S]=k*S;
		stack<ii > st;
		st.push(mp(k*S,k*S));
		for(int i=k*S-1;i>=0;--i){
			while(c[i]<g[i].size()&&g[i][c[i]]<=k*S)c[i]++;
			if(c[i]){
				c[i]--;
				int j=g[i][c[i]];
				assert(j<=k*S);
				while(!st.empty()&&st.top().fst<=j)j=max(j,st.top().snd),st.pop();
				w[k][i]=j;
				st.push(mp(i,j));
			}
			else w[k][i]=i;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		int j=b/S*S,r,i;
		if(j>=a)i=j,r=w[b/S][a];
		else i=r=a;
		while(i<b){
			i++;
			if(x[i]>=a&&x[i]<=r)r=i;
		}
		printf("%d\n",r+1);
	}
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