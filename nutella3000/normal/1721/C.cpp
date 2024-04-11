#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const ll infL = 1e18 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;

    vector<int> nxt(n);
    nxt[n-1] = b[n-1];
    for (int i = n-2; i >= 0; --i) {
        nxt[i] = nxt[i+1];
        if (a[i+1] > b[i]) nxt[i] = b[i];
    }

    for (int i = 0; i < n; ++i)
        cout << *lower_bound(b.begin(), b.end(), a[i]) - a[i] << " " ;
    cout << '\n';
    for (int i = 0; i < n; ++i)
        cout << nxt[i] - a[i] << " ";
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