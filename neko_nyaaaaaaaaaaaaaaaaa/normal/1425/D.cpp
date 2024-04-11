#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define N 2005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
const long long M = 1000000007;
using namespace std;
ll C[N][N];
 
void Combi(ll n, ll m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i < j)
                C[i][j] = 0;
            else if (i == j)
                C[i][j] = 1;
            else if (j == 0)
                C[i][j] = 1;
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
            }
        }
    }
}
 
ll choose(int n, int m) {
    return C[n][m] % M;
}
 
int n, m, r;
bitset<2000> adj[2000];
 
ll calc(int i) {
    int c = adj[i].count();
    int nc = n - c;
 
    ll tmp1 = choose(n, m);
    ll tmp2 = choose(nc, m);
 
    return (tmp1 - tmp2) % M;
}
 
ll calc(int i, int j) {
    int both = (adj[i] & adj[j]).count();
    int bi = adj[i].count() - both;
    int bj = adj[j].count() - both;
 
    // pick either
    // at least 1 from "both"
    // at least 1 from bi and at least 1 from bj
    ll ans = 0;
    //cout << "Calculating: " << i << ' ' << j << '\n';
    {
        // at least 1 from "both"
        int c = both, nc = n - c;
        ll tmp1 = choose(n, m);
        ll tmp2 = choose(nc, m);
 
        //cout << (tmp1-tmp2) << '\n';
 
        ans = (tmp1 - tmp2) % M;
    }
 
    {
        ll tmp = 0;
        // none from both, but at least 1 from bi and 1 from bj
        // they are disjoint lol
 
        // take none from bj
        tmp = (tmp + choose(n-both-bj, m)) % M;
 
        // take none from bi
        tmp = (tmp + choose(n-both-bi, m)) % M;
 
        // take none from any, inclusion exclusion
        tmp = (tmp - choose(n-both-bi-bj, m)) % M;
 
        // ans = complement lol
        ll tmp1 = choose(n - both, m);
        ll tmp2 = tmp;
 
        ans = (ans + (tmp1 - tmp2)) % M;
 
        //cout << bi << ' ' << bj << ' ' << (tmp1-tmp2) << '\n';
    }
    return ans;
}
 
int main()
{
    fastio;
    int testcase;
    reset(C, 0);
    Combi(2000, 2000);
 
    cin >> n >> m >> r;
    vector<ll> x(n), y(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> b[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(x[i] - x[j]) <= r && abs(y[i] - y[j]) <= r) {
                adj[i][j] = 1;
            }
        }
    }
 
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll val = (b[i]*b[j]) % M;
            if (i == j) {
                ans = (ans + val*calc(i)) % M;
            } else {
                ans = (ans + val*calc(i, j)) % M;
            }
        }
    }
 
    if (ans < 0) ans += M;
    cout << ans << '\n';
}