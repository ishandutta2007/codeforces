#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        priority_queue<int> pq;

        long long current_value = 0;
        for (int i = 0; i < n; i++) {
            int current = (s[i] == 'L' ? i : n - i - 1);
            current_value += current;
            pq.push(n - 1 - 2 * current);
        }

        for (int k = 1; k <= n; k++) {
            if (pq.top() > 0) {
                current_value += pq.top();
                pq.pop();
            }
            cout << current_value << ' ';
        }
        cout << '\n';
    }
    return 0;
}