#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e6 + 5;

ll n, m;
string a, b;

bool visited[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b;

    if (a.length() > b.length()) {
        swap(n, m);
        swap(a, b);
    }

    int len = 0;
    ll ans = 0;

    for (int i = 0; i < a.length(); i++) {
        if (!visited[i]) {
            vector<int> cnt1(26), cnt2(26);
            int ptr = i;
            len = 0;

            do {
                if (ptr < a.length()) {
                    cnt1[a[ptr] - 'a']++;
                }
                cnt2[b[ptr] - 'a']++;
                visited[ptr] = true;
                ptr = (ptr + a.length()) % b.length();
                len++;
            } while (ptr != i);

            int sum = accumulate(cnt2.begin(), cnt2.end(), 0);

            for (int j = 0; j < 26; j++) {
                ans += (ll)cnt1[j] * (sum - cnt2[j]);
            }
        }
    }

    cout << ans * (n / len) << "\n";
    return 0;
}