
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> used(n + 1);
    range(i, n) cin >> a[i];
    range(i, n) used[a[i]] = 1;
    vector<int> ch, nch;
    for(int i = 1; i <= n; ++i) {
        if ((i & 1) && (!used[i])) {
            nch.push_back(i);
        } else if(!used[i]) {
            ch.push_back(i);
        }
    }
    int ans = 0;
    int prev = -1, previ = -1;
    int bi = 0, b = -1;
    multiset<int> chp, nchp;
    for(int i = 0; i < n; ++i) {
        if (a[i]) {
            if (prev != -1 && a[i] % 2 != prev % 2) ans++;
            if(prev != -1 && a[i] % 2 == prev % 2) {
                if (a[i] % 2) nchp.insert(i - previ - 1);
                else chp.insert(i - previ - 1);
            } else if (prev == -1) {
                bi = i;
                b = a[i];
            }
            prev = a[i];
            previ = i;
        }
    }
    int chetn = ch.size();
    int nechetn = nch.size();
    while(!chp.empty() && chetn >= *chp.begin()) {
        chetn -= *chp.begin();
        chp.erase(chp.begin());
    }
    while(!nchp.empty() && nechetn >= *nchp.begin()) {
        nechetn -= *nchp.begin();
        nchp.erase(nchp.begin());
    }
    if (bi > n - previ - 1) {
        if (prev % 2) {
            if (nechetn >= n - previ - 1) {
                nechetn -= n - previ - 1;
                previ = -10000000;
                ans--;
            } else {
                ans++;
            }
        } else {
            if (chetn >= n - previ - 1) {
                chetn -= n - previ - 1;
                previ = -1000000000;
                ans--;
            } else {
                ans++;
            }
        }
    }
    if (b % 2) {
        if (nechetn >= bi) {
            nechetn -= bi;
        } else {
            ans++;
        }
    } else {
        if (chetn >= bi) {
            chetn -= bi;
        } else {
            ans++;
        }
    }
    if (prev % 2) {
        if (nechetn >= n - previ - 1) {
            nechetn -= n - previ - 1;
        } else {
            ans++;
        }
    } else {
        if (chetn >= n - previ - 1) {
            chetn -= n - previ - 1;
        } else {
            ans++;
        }
    }
    cout << ans + chp.size() * 2 + nchp.size() * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    //cin >> tests;
    tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}