#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    vector<int> cnt(101);
    range(i, n) {
        int x; cin >> x;
        cnt[x]++;
    }
    int j = 0;
    vector<int> b;
    range(i, n) {
        if (!cnt[j]) break;
        b.push_back(j);
        cnt[j]--;
        j++;
    }
    range(i, 101) {
        while(cnt[i]) {
            b.push_back(i);
            cnt[i]--;
        }
    }
    for(auto &x : b) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}