#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

const int B = 1000;

const int MAX = 50000000;

int cnt[2 * MAX];

int main() {
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    cerr << n << endl;

    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (s[i] - '0');
    }

    cerr << "!!!" << endl;

    long res = 0;


    for (int k = 1; k < B; k++) {
        for (int q = 0; q < k; q++) {
            for (int r = q; r <= n; r += k) {
                if (p[r] - k >= 0)
                    res += cnt[p[r] - k];
                cnt[p[r]]++;
            }
            for (int r = q; r <= n; r += k) {
                cnt[p[r]]--;
            }
        }
    }

    cerr << res << endl;

    for (int x = 1; x * B <= n; x++) {
        for (int r = 0; r <= n; r++) {
            if (r >= B * x) {
                cnt[x * p[r - B * x] - (r - B * x) + MAX]++;
            }
            res += cnt[x * p[r] - r + MAX];
        }
        for (int r = 0; r <= n; r++) {
            if (r >= B * x) {
                cnt[x * p[r - B * x] - (r - B * x) + MAX]--;
            }
        }
    }

    cout << res << "\n";

    return 0;
}