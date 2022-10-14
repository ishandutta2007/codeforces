#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    priority_queue<lint> sml;
    priority_queue<lint, vector<lint>, greater<lint>> big;
    
    lint N, M;
    lint sum = 0;
    cin >> N >> M;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        while (big.size() && sml.size() && big.top() < sml.top()) {
            sml.emplace(big.top());
            sum += big.top();
            sum -= sml.top();
            big.emplace(sml.top());
            big.pop();
            sml.pop();
        }
        int t; cin >> t;
        sum += t;
        while (sum > M) {
            sum -= sml.top();
            big.emplace(sml.top());
            sml.pop();
        }
        while (big.size() && sum + big.top() <= M) {
            sum += big.top();
            sml.emplace(big.top());
            big.pop();
        }
        if (sum <= M) {
            ans.emplace_back(big.size());
        }

        sml.emplace(t);
    }
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}