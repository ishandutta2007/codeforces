#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
 
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;
const int mod = 998244353;

void run() {
    int n, m; cin >> n >> m;
    cout << (n-1) + (m-1) + (n == 1 && m == 1 ? 0 : min(n, m)) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}