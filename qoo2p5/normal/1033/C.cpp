#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long INF = (long long) 1e12 + 100;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n;
int a[N];
bool dp[N];
int where[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        where[a[i]] = i;
    }
    for (int x = n; x >= 1; x--) {
        int i = where[x];
        for (int d = a[i]; d + i <= n; d += x) {
            if (a[d + i] <= x) continue;
            dp[x] |= !dp[a[d + i]];
        }
        for (int d = a[i]; i - d >= 1; d += x) {
            if (a[i - d] <= x) continue;
            dp[x] |= !dp[a[i - d]];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (dp[a[i]] ? "A" : "B");
    }
    cout << "\n";
}