#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, a[N], degree[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) cin >> a[i], degree[a[i]]++;

    int root = a[1];
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 1; i <= n; i++) {
        if (i != root) {
            if (!degree[i]) {
                pq.push(i);
            }
            degree[i]++;
        }
    }

    cout << root << '\n';
    for (int i = n - 1; i >= 1; i--) {
        int x = pq.top();
        pq.pop();

        cout << a[i] << ' ' << x << '\n';
        degree[a[i]]--;

        if (a[i] != root and degree[a[i]] == 1) {
            pq.push(a[i]);
        }
    }
    return 0;
}