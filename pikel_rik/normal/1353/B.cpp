#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int a[31], b[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a, a + n); sort(b, b + n);

        int ans = accumulate(a + k, a + n, 0);

        priority_queue<int> q;
        for (int i = 0; i < k; i++)
            q.push(a[i]), q.push(b[n - i - 1]);

        for (int i = 0; i < k; i++) {
            int temp = q.top();
            ans += temp;
            q.pop();
        }

        cout << ans << "\n";
    }
    return 0;
}