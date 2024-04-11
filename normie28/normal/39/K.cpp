
// Problem : K. Testing
// Contest : Codeforces - School Team Contest #1 (Winter Computer School 2010/11)
// URL : https://codeforces.com/contest/39/problem/K
// Memory Limit : 64 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
string a[1005];
int b[1005][1005];
int Q[2000005];
int L[105], R[105], D[105], U[105];
 
int dx[4] = {1, 0, -1, 0} , dy[4] = {0, 1, 0, -1};
 
void go(int x, int y, int w) {
	b[x][y] = w;
	int qb=0, qe=0;
	L[w]=R[w]=x;
	D[w]=U[w]=y;
	Q[qe++] = x;
	Q[qe++] = y;
	while(qb < qe) {
		x = Q[qb++];
		y = Q[qb++];
		for(int k=0;k<4;k++)
			if(a[x+dx[k]][y+dy[k]]=='*' && b[x+dx[k]][y+dy[k]]==0) {
				b[x+dx[k]][y+dy[k]]=w;
				L[w] = min(L[w], x+dx[k]);
				R[w] = max(R[w], x+dx[k]);
				U[w] = max(U[w], y+dy[k]);
				D[w] = min(D[w], y+dy[k]);
				Q[qe++] = x+dx[k];
				Q[qe++] = y+dy[k];
			}
	}
}
 
int n, m, k;
ll ans;
int LDY[1005], LUY[1005], LDX[1005], RDX[1005];
int RUX[1005], RUY[1005], gsum[1005];
void chk(int p, int q, int s) {
	int l, r, d, u, ll, rr, dd, uu;
	l = min(L[p], min(L[q], L[s]));
	r = max(R[p], max(R[q], R[s]));
	d = min(D[p], min(D[q], D[s]));
	u = max(U[p], max(U[q], U[s]));
	ll=0;rr=n+1;
	dd=0;uu=m+1;
	for(int i=1;i<=k;i++) {
		if(i==p || i==q || i==s) continue;
		if(R[i] >= l && L[i] <= r) {
			if(U[i] < d) dd = max(dd, U[i]);
			else if(D[i] > u) uu = min(uu, D[i]);
			else return;
		}
		if(U[i] >= d && D[i] <= u) {
			if(R[i] < l) ll = max(ll, R[i]);
			else if(L[i] > r) rr = min(rr, L[i]);
			else return;
		}
	}
	for(int x=ll+1;x<=l;x++) LDY[x] = dd+1, LUY[x] = uu-1;
	for(int y=dd+1;y<=d;y++) LDX[y] = ll+1, RDX[y] = rr-1;
	for(int x=r;x<rr;x++) RUY[x] = uu-1;
	for(int y=u;y<uu;y++) RUX[y] = rr-1;
 
	for(int i=1;i<=k;i++) {
		if(i==p || i==q || i==s) continue;
		if(R[i] < l && U[i] < d) {
			LDY[R[i]] = max(LDY[R[i]], U[i]+1);
			LDX[U[i]] = max(LDX[U[i]], R[i]+1);
		} else if(R[i] < l && D[i] > u) {
			LUY[R[i]] = min(LUY[R[i]], D[i]-1);
		} else if(L[i] > r && U[i] < d) {
			RDX[U[i]] = min(RDX[U[i]], L[i]-1);
		} else if(L[i] > r && D[i] > u) {
			RUY[L[i]] = min(RUY[L[i]], D[i]-1);
			RUX[D[i]] = min(RUX[D[i]], L[i]-1);
		}
	}
	for(int x=l-1;x>ll;x--) {
		LDY[x] = max(LDY[x], LDY[x+1]);
		LUY[x] = min(LUY[x], LUY[x+1]);
	}
	for(int y=d-1;y>dd;y--) {
		LDX[y] = max(LDX[y], LDX[y+1]);
		RDX[y] = min(RDX[y], RDX[y+1]);
	}
	for(int x=r+1;x<rr;x++)
		RUY[x] = min(RUY[x], RUY[x-1]);
	for(int y=u+1;y<uu;y++)
		RUX[y] = min(RUX[y], RUX[y-1]);
	gsum[r] = 0;
	for(int x=r+1;x<rr;x++)
		gsum[x] = gsum[x-1] + (RUY[x] - u + 1);
 
	for(int x=ll+1;x<=l;x++)
		for(int y=LDY[x];y<=d;y++) {
			int yu = LUY[x];
			int xr = RDX[y];
			int xyu = RUX[yu];
			//int yxr = RUY[xr];
			if(xr <= xyu) {
				ans += 1LL*(yu-u+1)*(xr-r+1);
			} else {
				ans += 1LL*(yu-u+1)*(xyu-r+1)+gsum[xr]-gsum[xyu];
			}
		}
}
 
int main(void) {
	fio;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=" "+a[i];
	}
	int w=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='*' && b[i][j]==0) {
				go(i, j, ++w);
			}
 
	ans = 0;
	for(int i=1;i<=w;i++)
		chk(i, i, i);
	for(int i=1;i<=w;i++)
		for(int j=i+1;j<=w;j++)
			chk(i, j, j);
	for(int i=1;i<=w;i++)
		for(int j=i+1;j<=w;j++)
			for(int e=j+1;e<=w;e++)
				chk(i, j, e);
	cout<<ans;
}