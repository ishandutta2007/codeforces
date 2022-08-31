#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 150000 + 5;

int n, a[N], cnt[N];
bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

    if (cnt[1]) {
        visited[1] = true;
        if (cnt[1] > 1) {
            visited[2] = true;
        }
    }
    for (int i = 2; i < N; i++) {
        if (!cnt[i]) continue;

        if (cnt[i] == 1) {
            if (!visited[i - 1]) {
                visited[i - 1] = true;
            } else if (!visited[i]) {
                visited[i] = true;
            } else {
                visited[i + 1] = true;
            }
        } else if (cnt[i] == 2) {
            if (!visited[i - 1]) {
                visited[i - 1] = visited[i] = true;
            } else {
                visited[i] = visited[i + 1] = true;
            }
        } else {
            visited[i - 1] = visited[i] = visited[i + 1] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i < N; i++) {
        ans += visited[i];
    }
    cout << ans << '\n';
    return 0;
}