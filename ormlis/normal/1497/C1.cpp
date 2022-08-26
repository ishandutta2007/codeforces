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
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    if (n % 2 == 1) {
        ans.push_back(1);
        n--;
        ans.push_back(n / 2);
        ans.push_back(n / 2);
    } else if (n % 4 == 0) {
        ans.push_back(n / 2);
        ans.push_back(n / 4);
        ans.push_back(n / 4);
    } else {
        ans.push_back(2);
        n -= 2;
        ans.push_back(n / 2);
        ans.push_back(n / 2);
    }
    for(auto &i : ans) cout << i << ' ';
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