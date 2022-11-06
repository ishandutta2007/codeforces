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

int n, m, h;
int u[100010];
int c[100010][2];

void in(){
	read(n, m, h);
	for(int i=1; i<=n; ++i) read(u[i]);
	for(int i=1; i<=m; ++i) read(c[i][0], c[i][1]);
}

vector<int> e[100010];
int nt, ind[100010], low[100010], stk[100010], top;
bool onstk[100010];
int sz[100010], my[100010], sn;
bool eo[100010];
void dfs(int x){
	ind[x] = low[x] = ++nt;
	onstk[x]=1; stk[top++]=x;
	for(int y:e[x]){
		if(!ind[y]){
			dfs(y);
			low[x]=min(low[x], low[y]);
		} else if(onstk[y]) low[x]=min(low[x], ind[y]);
	}
	if(ind[x] == low[x]){
		++sn;
		for(;top--;){
			int a=stk[top];
			onstk[a]=0;
			++sz[sn]; my[a]=sn;
			if(a==x) break;
		}
	}
}

int main()
{
	in();
	for(int i=1; i<=m; ++i){
		int A=c[i][0], B=c[i][1];
		if((u[A]+1)%h == (u[B])%h) e[A].pb(B);
		if((u[B]+1)%h == (u[A])%h) e[B].pb(A);
	}
	for(int i=1; i<=n; ++i)if(!ind[i]) dfs(i);
	for(int i=1; i<=n; ++i) for(int j:e[i]){
		if(my[i]!=my[j]) eo[my[i]]=1;
	}
	int ai=-1;
	for(int i=1; i<=sn; ++i) if(!eo[i]){
		if(ai==-1 || sz[i]<sz[ai]) ai=i;
	}
	printf("%d\n", sz[ai]);
	for(int i=1; i<=n; ++i) if(my[i]==ai) printf("%d ", i);
	return 0;
}