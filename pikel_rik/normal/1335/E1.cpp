#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vi count(27), running_count(27);
        for (int i : a) {
            count[i] += 1;
        }

        int best = *max_element(count.begin(), count.end());
        for (int i = 0; i < n; i++) {
            running_count[a[i]] += 1;

            if (running_count[a[i]] <= count[a[i]] / 2) {
                vi count1(27);
                for (int j = i + 1; j < n; j++) {
                    count1[a[j]] += 1;
                    if (2 * running_count[a[i]] + count1[a[i]] > count[a[i]])
                        break;
                }

                int m = INT_MIN;
                for (int j = 1; j <= 26; j++) {
                    if (a[i] == j) continue;
                    m = max(m, count1[j]);
                }

                best = max(best, 2 * running_count[a[i]] + m);
            }
        }

        cout << best << "\n";
    }
    return 0;
}