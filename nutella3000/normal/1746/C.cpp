#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15 + 7;
const ll mod = 1e9 + 7;
const int N = 1e6 + 5;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;

    vector<int> ids(n-1);
    iota(all(ids), 0);
    sort(all(ids), [&a](int u, int v) { return a[u]-a[u+1] > a[v] - a[v+1]; });

    vector<int> res;
    for (int i : ids) {
        res.push_back(i+2);
    }
    res.push_back(1);
    reverse(all(res));
    for (auto i : res)
        cout << i << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}