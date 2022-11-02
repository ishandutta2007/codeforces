#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define mp make_pair
#define siz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb emplace_back


void run() {
    int n; cin >> n;
    multiset<int> a;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        sum += v;
        a.emplace(v);
    }
    multiset<int> b = {sum};


    for (int it = 0; it < 2*n-1; ++it) {
        int x = *b.begin(); b.erase(b.begin());
        if (a.find(x) != a.end()) {
            a.erase(a.find(x));
        } else {
            b.emplace(x/2);
            b.emplace((x+1)/2);
        }
    }

    cout << (siz(b) ? "NO" : "YES") << endl;
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}