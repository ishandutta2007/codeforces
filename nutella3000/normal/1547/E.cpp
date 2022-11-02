#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k), t(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        cin >> t[i];
    vector<int> so(k);
    iota(all(so), 0);
    sort(all(so), [&](int v1, int v2) { return a[v1] < a[v2]; });

    //t[i] + a[i] - j;
    //t[i] - a[i] + j
    auto comp1 = [&](int v1, int v2) { return mp(t[v1] - a[v1], v1) < mp(t[v2] - a[v2], v2); };
    auto comp2 = [&](int v1, int v2) { return mp(t[v1] + a[v1], v1) < mp(t[v2] + a[v2], v2); };
    set<int, decltype(comp1)> s1(comp1);
    set<int, decltype(comp2)> s2(comp2);
    for (int i = 0; i < k; ++i)
        s2.insert(i);

    int id = 0;
    for (int i = 1; i <= n; ++i) {
        if (id < k && a[so[id]] == i) s2.erase(so[id]), s1.insert(so[id]), ++id;
        int l = (s1.empty() ? k : *s1.begin());
        int r = (s2.empty() ? k : *s2.begin());
        int v1 = (l == k ? inf : t[l] - a[l] + i);
        int v2 = (r == k ? inf : t[r] + a[r] - i);
        cout << min(v1, v2) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}