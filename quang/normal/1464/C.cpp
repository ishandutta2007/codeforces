#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long t;
char s[N];
int cnt[60];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> t;
    cin >> (s + 1);
    for (int i = 1; i <= n - 2; i++) {
        cnt[s[i] - 'a' + 1]++;
    }
    t -= (1ll << (s[n] - 'a'));
    t += (1ll << (s[n - 1] - 'a'));
    for (int i = 1; i <= n - 2; i++) {
        t += 1ll << (s[i] - 'a');
    }
    if (t < 0) {
        cout << "No\n";
        return 0;
    }
    for (int i = 59; i >= 0; i--) {
        while (cnt[i] && t >= (1ll << i)) {
            t -= 1ll << i;
            cnt[i]--;
        }
    }
    cout << (t ? "No" : "Yes") << '\n';
    return 0;
}