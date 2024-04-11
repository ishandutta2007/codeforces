<<<<<<< HEAD
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define O4 __inline__ __attribute__((always_inline))
#ifdef ONLINE_JUDGE
#define getchar nc
#endif
const int lim=4005;
struct node{int x,l,r;}w[lim];
int s[lim][lim],n,k,f[lim],g[lim],heat,tail;
int F(int x,int y,int z){return (s[x][x]+s[y][y]-2*s[x][y])/2+f[y]+z;}
namespace FastIO{
	O4 char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
	}
	O4 int read(){
		char t;int u=0,k=1;t=getchar();
		while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
		while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
		return u*k;
	}
}
using namespace FastIO;
void work(int x)
{
	heat=1,tail=1;int i;
	f[0]=g[0]=0;w[tail]=(node){0,1,n};
	for(i=1;i<=n;i++)
	{
		while(heat<tail&&w[heat].r<i)heat++;
		f[i]=F(i,w[heat].x,x),g[i]=g[w[heat].x]+1;
		if(F(n,i,x)>=F(n,w[tail].x,x))continue;
		while(heat<tail&&F(w[tail].l,w[tail].x,x)>F(w[tail].l,i,x))tail--;
		int l=w[tail].l,r=w[tail].r+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(F(mid,i,x)<F(mid,w[tail].x,x))r=mid;
			else l=mid+1;
		}
		w[tail].r=r-1;
		w[++tail]=(node){i,r,n};
	}
}
int main()
{
	int i,j,x;
	n=read();k=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x=read();
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
		}
	}
	int l=0,r=s[n][n],ans;
	while(l<r)
	{
		int mid=(l+r)>>1;
		work(mid);
		if(g[n]>k){l=mid+1;}
		else r=mid;
	}
	work(r);printf("%d",f[n]-r*k);
=======
#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int pre[MAXN], cur[MAXM], cost[MAXN][MAXN], ps[MAXN][MAXN];

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void dfs(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l+r) >> 1;
    pair<int, int> best = {INF, -1};
    for (int k = optl; k <= min(mid, optr); k++) best = min(best, {(k?pre[k-1]:0)+cost[k][mid], k});
    cur[mid] = best.first;
    dfs(l, mid - 1, optl, best.second), dfs(mid + 1, r, best.second, optr);
}
void solve(){
    int n, K; cin >> n >> K;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            char c; cin >> c; c -= '0';
            ps[i][j] = (j?ps[i][j-1]:0)+c;
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++){
        cost[i][i] = 0; pre[i] = cur[i] = INF;
        for (int j = i+1; j < n; j++){
            cost[i][j] = cost[i][j-1]+ps[j][j]-(i?ps[j][i-1]:0);
        }
    }
    for (int k = 1; k <= K; k++){
        dfs(0, n-1, 0, n-1);
        for (int i = 0; i < n; i++) pre[i] = cur[i];
    }
    cout << pre[n-1];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
>>>>>>> ba48ae4a69f706fe86df6abfbbc02a36ff86f577
}