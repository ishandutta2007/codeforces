#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        int h[n];
        for (int i = 0; i < n; i++) cin >> h[i];
        priority_queue<pair<int,int>> q;
        for (int i = 1; i <= m; i++) {
            q.push({0,i});
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            auto t = q.top(); q.pop();
            cout << t.second << " ";
            t.first -= h[i];
            q.push(t);
        }
        cout << "\n";
    }
}