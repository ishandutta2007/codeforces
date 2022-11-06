#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, q;
vector<int> e[300010];

int sz[300010];
int mcs[300010];
int nxt[19][300010];

void dfs(int x){
	sz[x]=1;
	int mc=-1;
	for(int y:e[x]){
		dfs(y);
		sz[x]+=sz[y];
		if(mc == -1 || sz[mc]<sz[y]) mc=y;
	}
	if(mc == -1) mc=x;
	else mcs[x]=sz[mc];
	nxt[0][x]=mc;
	for(int i=1; i<=18; ++i) nxt[i][x]=nxt[i-1][nxt[i-1][x]];
}

int main()
{
	read(n, q);
	for(int p,i=2; i<=n; ++i) read(p), e[p].pb(i);
	dfs(1);
	for(;q--;){
		int r; read(r); int s=sz[r];
		int cr=r;
		for(int i=18; 0<=i; --i){
			int t=nxt[i][cr];
			if(mcs[t]>s/2) cr=t;
		}
		while(s-sz[cr]>s/2 || mcs[cr]>s/2) cr=nxt[0][cr];
		printf("%d\n", cr);
	}
	return 0;
}