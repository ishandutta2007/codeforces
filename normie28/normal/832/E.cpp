// Problem : E. Awards For Contestants
// Contest : Codeforces - Educational Codeforces Round 30
// URL : https://codeforces.com/problemset/problem/873/E
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
 
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
 
char s[505];
int n, m, q;
int a[500][500];
int inv[5] = {0, 1, 3, 2, 4};
int b[500];
int can[500];
 
int pre() {
    memset(can, -1, sizeof can);
    int row = 0;
    forn(col, m) {
        bool found = false;
        for (int i = row; i < n; ++i) if (a[i][col] != 0) {
            forn(j, m) swap(a[i][j], a[row][j]);
            found = true;
            break;
        }
        if (!found) {
            continue;
        }
        can[col] = row;
        int mul = inv[a[row][col]];
        forn(j, m) {
            a[row][j] = mul * a[row][j] % 5;
        }
        forn(i, n) if (i != row && a[i][col] > 0) {
            mul = 5 - a[i][col];
            forn(j, m) {
                a[i][j] = (a[i][j] + mul * a[row][j]) % 5;
            }
        }
        if (++row == n) {
            break;
        }
    }
    int ans = 1;
    while (row != n) {
        ans = 5ll * ans % MOD;
        ++row;
    }
    return ans;
}
 
int solve() {
    forn(i, m) if (b[i] != 0 && can[i] != -1) {
        while (b[i] != 0) {
            forn(j, m) {
                b[j] += a[can[i]][j];
                if (b[j] >= 5) b[j] -= 5;
            }
        }
    }
    forn(i, m) if (b[i] != 0) return false;
    return true;
}
 
int main() {
    cin>>n>>m;
    forn(i, n) {
        scanf("%s", s);
        forn(j, m) a[i][j] = s[j] - 'a';
    }
    scanf("%d", &q);
    int mul = pre();
    forn(i, q) {
        scanf("%s", s);
        forn(j, m) b[j] = s[j] - 'a';
        printf("%d\n", mul * solve());
    }
}