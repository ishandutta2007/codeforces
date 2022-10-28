#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int g[MAXN][MAXN];
int a1[MAXN][MAXN], a2[MAXN][MAXN]; //a1 is for rows, a2 is for columns
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < n; j++) g[i][j] = (s[j]=='B')+(i?g[i-1][j]:0)+(j?g[i][j-1]:0)-(i&&j?g[i-1][j-1]:0);
    }
    auto get = [&](int i1, int i2, int j1, int j2){
        return g[i2][j2]-(i1?g[i1-1][j2]:0)-(j1?g[i2][j1-1]:0)+(i1&&j1?g[i1-1][j1-1]:0);
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j+k <= n; j++)
            a1[i][j] = (get(i, i, j, j+k-1) == get(i, i, 0, n-1) && get(i, i, 0, n-1))+(i?a1[i-1][j]:0);
    for (int i = 0; i+k <= n; i++)
        for (int j = 0; j < n; j++)
            a2[i][j] = (get(i, i+k-1, j, j) == get(0, n-1, j, j) && get(0, n-1, j, j))+(j?a2[i][j-1]:0);
    int cur=0;
    for (int i = 0; i < n; i++)
        cur += !get(i, i, 0, n-1), cur += !get(0, n-1, i, i);
    auto getAns = [&](int i, int j){
        return a1[i+k-1][j]-(i?a1[i-1][j]:0)+a2[i][j+k-1]-(j?a2[i][j-1]:0);
    };
    int ans=0;
    for (int i = 0; i+k <= n; i++){
        for (int j = 0; j+k <= n; j++){
            ans = max(ans, getAns(i, j));
        }
    }
    cout << (ans+cur) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}