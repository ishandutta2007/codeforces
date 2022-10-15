
// Problem : D. Donkey and Stars
// Contest : Codeforces - Codeforces Round #152 (Div. 1)
// URL : https://codeforces.com/problemset/problem/249/D
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
#define ff first
#define ss second
#define MAXN 300005
#define INF 1000000LL
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define int long long
//---------END-------//
 
const int mod = 1000000007;
int n, i, j, cnt, res[MAXN], f[MAXN];
pair<int, int> p[MAXN];
map <int, int> mp;
char ch;
 
int get(int n){
    int ans = 0, i;
 
    for(i = n; i >= 0; i = (i & (i + 1)) - 1)
        ans = max(ans, f[i]);
 
    return ans;
}
 
void upd(int pos, int val){
 
    for(i = pos; i < cnt; i |= i + 1)
        f[i] = max(f[i], val);
 
}
 
signed main(){
	fio;
    cin.tie(0);
    int x, y, a, b, c, d, r, ans = 0;
 
    cin >> n;
    cin >> a >> ch >> b;
    cin >> c >> ch >> d;
 
    for(i = 0; i < n; i++){
        cin >> x >> y;
 
        p[i] = {a * x - b * y, -(c * x - d * y)};
 
        mp[p[i].ss] = 1;
        mp[p[i].ss - 1] = 1;
    }
 
    map <int, int> :: iterator it = mp.begin();
 
    while(it != mp.end()){
 
        it -> ss = cnt++;
 
        ++it;
    }
 
    sort(p, p + n);
 
    for(i = 0; i < n; i++){
        r = i;
        while(r + 1 < n && p[i].ff == p[r + 1].ff)
            r++;
 
        for(j = i; j <= r; j++){
            res[j] = 1 + get(mp[p[j].ss - 1]);
 
            if(p[j].ff < 0 && p[j].ss < 0)
                ans = max(ans, res[j]);
        }
 
        for(j = i; j <= r; j++)
            upd(mp[p[j].ss], res[j]);
 
        i = r;
    }
 
    cout << ans;
}