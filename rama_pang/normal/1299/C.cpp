#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) x.size()

using lint = long long;
const int MAXN = 1000005;

lint A[MAXN], pref[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int N;
    cin >> N;
    vector<pair<lint, int>> ans;
        
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        pair<lint, int> seg = {A[i], 1};
        while (sz(ans) && double(1.00 * ans.back().first / ans.back().second) > double(1.00 * seg.first / seg.second)) {
            seg.first += ans.back().first;
            seg.second += ans.back().second;
            ans.pop_back();
        }
        ans.emplace_back(seg);
    }

    cout << fixed << setprecision(10);
    for (auto &i : ans) {
        for (int j = 0; j < i.second; j++) {
            cout << double(1.00 * i.first / i.second) << "\n";
        }
    }
}