#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9;

map<int, int> b;

bool check(pii a) {
    auto it = b.lower_bound(a.fi);
    return it == b.end() || it->se < a.se;
}

void add(pii a) {
    while(true) {
        auto it = b.upper_bound(a.fi);
        if (it == b.begin()) break;
        it--;
        if (it->se <= a.se) b.erase(it);
        else break;
    }
    b.emplace(a);
}

void solve() {
    int n;
    cin >> n;

    int res = 0;

    auto comp = [](int v1, int v2) {return v1 > v2;};

    map<int, vector<pii>, decltype(comp)> a(comp);

    vector<int> a1(n), a2(n), a3(n);

    for(int i = 0;i < n;i++) 
        cin >> a1[i];
    for(int i = 0;i < n;i++)
        cin >> a2[i];
    for(int i = 0;i < n;i++)
        cin >> a3[i];

    for(int i = 0;i < n;i++) {
        a[a1[i]].emplace_back(a2[i], a3[i]);
    }
    

    for(auto temp1 : a) {
        for(auto wom : temp1.se) {
            res += !check({wom.fi + 1, wom.se + 1});
        }
        for(auto wom : temp1.se) {
            if (check(wom))
                add(wom);
        }
    }

    cout << res;
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}