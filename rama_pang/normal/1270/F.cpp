#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int N = 200005;
const int MAX = 250;

int cnt[N * (MAX + 5)];
int pref[N];

/*  
    (j - i + 1) = k(pref[j] - pref[i - 1])
    j - k * pref[j] = (i - 1) - k * pref[i - 1]
    Problem is equal to count pairs (i - k * pref[i]) for k = 1...N

    For k <= MAX, count it manually using cnt array
    For k > MAX, notice that (j - i + 1) / k <= n / MAX, and
    pref[r] - pref[l - 1] = (j - i + 1) / k <= n / MAX
    So the number of '1's we need to consider are <= n / MAX

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    
    int n = s.size();
    lint ans = 0;

    for (int i = 0; i < n; i++) {
        pref[i + 1] = s[i] - '0';
        pref[i + 1] += pref[i];
    }

    for (int k = 1; k <= MAX; k++) {
        for (int i = 0; i <= n; i++) {
            ans += cnt[k * pref[i] - i + n]++;
        }
        for (int i = 0; i <= n; i++) {
            cnt[k * pref[i] - i + n]--;
        }
    }

    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones.emplace_back(i + 1);
        }
    }
    ones.emplace_back(n + 1);

    int i = 0;
    int num = (int) ones.size() - 1;
    for (int l = 1; l <= n; l++) {
        while (i < num && ones[i] < l) {
            i++;
        }
        for (int j = i; j < num; j++) {
            if ((j - i + 1) * MAX > n) {
                break;
            }
            int high = (ones[j + 1] - l) / (j - i + 1);
            int low = max(MAX, (ones[j] - l) / (j - i + 1));
            ans += max(high - low, 0);
        }
    }

    cout << ans << "\n";
    return 0;
}