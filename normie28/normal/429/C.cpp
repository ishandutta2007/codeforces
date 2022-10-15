
// Problem : C. Guess the Tree
// Contest : Codeforces - Codeforces Round #245 (Div. 1)
// URL : https://codeforces.com/problemset/problem/429/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define F first
#define S second
#define pb push_back
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef long long ll;
//---------END-------//
int n,m,k,a[200],pos[100001],t,t1,i,j;
set <int> S[30];
void dfs(int mask, int t)
{
    S[t].insert(mask);
    if (mask == (1 << (n - 1)) - 1){
        cout << "YES";
        exit(0);
        }
    if (t == n) return;
    int b[30], k = 0, c[30];
    for (int i = 0; i <= 30; i++)c[i] = 0;
    for (int i = 1; i <= t; i++)
    if (mask & (1 << (i -  1)))
        b[i] = 1;
    else{
        c[k] = i;
        k++;
    }
    for (int i = 0; i < (1 << k); i++){
        int f = 0;
        int s = 0;
        int cc = 0;
        for (int j = 0; j < k; j++)
        if (i & (1 << j)){
            s += a[c[j]];
            f += (1 << (c[j] - 1));
            cc++;
        }
        if (s + 1 == a[t + 1] && cc > 1 && S[t + 1].count(mask + f) == 0)
                dfs(mask + f, t + 1);
    }
}
int main()
{
	fio;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int t = 0;
    while(a[t + 1] == 1) t++;
    dfs(0, t);
    cout << "NO";
}