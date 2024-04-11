#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <numeric>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;

void solve() {
    int n, m;
    cin >> n >> m;
    ll g = 0;
    vector<ll> vals(n);
    vector<vector<int>> adj(n);
    foru(i, 0, n) {
        cin >> vals[i];
    }
    map<vector<int>, ll> mem;
    foru(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[--y].push_back(--x);
    }
    foru(i, 0, n) {
        sort(adj[i].begin(), adj[i].end());
        mem[adj[i]] += vals[i];
    }
    for (auto ii : mem) {
        if (!ii.ff.empty())
            g = gcd(g, ii.ss);
    }
    cout << g << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}