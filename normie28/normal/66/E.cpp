
// Problem : E. Petya and Post
// Contest : Codeforces - Codeforces Beta Round #61 (Div. 2)
// URL : https://codeforces.com/problemset/problem/66/E
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
#define all(x) (x).begin(), (x).end()
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
const int INF = (int)1e9;
 
const int maxN = 1.1e4;
 
set<int> ans;
 
void solve(vector<int> a, vector<int> b, int rev) {
    int n = a.size();
 
    if (rev) {
        reverse(all(a));
        reverse(all(b));
        int fr = b[0];
        for (int i = 0; i + 1 < n; i++) {
            b[i] = b[i + 1];
        }
        b[n - 1] = fr;
    }
    vector<int> s(2 * n + 2);
    for (int i = 0; i < n; i++) {
        s[i + n + 1] = s[i + 1] = a[i] - b[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        s[i] += s[i - 1];
    }
    multiset<int> ss;
    for (int i = 0; i < n; i++) {
        ss.insert(s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (*ss.begin() >= s[i]) {
            if(!rev)
                ans.insert(i + 1);
            else
                ans.insert(n - i);
        }
        ss.erase(s[i]);
        ss.insert(s[i + n]);
    }
}
 
int main() {
	fio;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    solve(a, b, 0);
    solve(a, b, 1);
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}