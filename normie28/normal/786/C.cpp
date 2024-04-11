
// Problem : C. Till I Collapse
// Contest : Codeforces - Codeforces Round #406 (Div. 1)
// URL : https://codeforces.com/problemset/problem/786/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j;
int dat[100005];
int ans[100005];
int ttt[100005];
bool yes[100005];
int tt;
 
int naive(int color)
{
    int res = 1;
    int now = 0;
    ++tt;
    for (int i = 0; i < n; i++)
    {
        int d = dat[i];
        if (ttt[d] != tt)
        {
            ttt[d] = tt;
            yes[d] = false;
        }
 
        if (yes[d] == false)
        {
            if (now == color)
            {
                ++res;
                ttt[d] = ++tt;
                now = 0;
            }
            ++now;
        }
 
        yes[d] = true;
    }
    return res;
}
 
void divide_and_conquer(int l, int r, int lo, int hi)
{
    if (l > r) return;
 
    int mid = (l + r) / 2;
    int res = lo == hi ? lo : naive(mid);
    ans[mid] = res;
    divide_and_conquer(l, mid - 1, res, hi);
    divide_and_conquer(mid + 1, r, lo, res);
}
 
int main()
{
	fio;
	cin>>n;
    for (int i = 0; i < n; i++) cin>>dat[i];
 
    ans[n] = 1;
    ans[1] = naive(1);
    divide_and_conquer(2, n - 1, 1, ans[1]);
 
    for (int i = 1; i <= n; i++) cout<<ans[i]<<' ';
    cout<<endl;
}