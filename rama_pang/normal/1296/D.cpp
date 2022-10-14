#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<lint> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    priority_queue<lint, vector<lint>, greater<lint>> pq;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > (a + b)) {
            h[i] %= (a + b);
            if (h[i] == 0) {
                h[i] += (a + b);
            }
        }
        
        pq.emplace((lint) ceil((1.00 * h[i]) / a) - 1);
    }
    while (k > 0 && !pq.empty()) {
        if (k >= pq.top()) {
            // cout << pq.top() << "\n";
            k -= pq.top();
            pq.pop();
            
            ans++;
        } else {
            break;
        }
    }
    cout << ans << "\n";
}