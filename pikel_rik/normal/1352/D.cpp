#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int i = 0, j = n - 1, prev1 = 0, prev2 = 0, sum1 = 0, sum2 = 0, c = 1, turns = 0;

        while (i <= j) {
            int sum = 0;
            if (c == 1) {
                while (sum <= prev2 and i <= j) {
                    sum += a[i];
                    i += 1;
                }
                prev1 = sum;
                sum1 += sum;
                c = 2;
            }
            else {
                while (sum <= prev1 and i <= j) {
                    sum += a[j];
                    j -= 1;
                }
                prev2 = sum;
                sum2 += sum;
                c = 1;
            }
            turns += 1;
        }

        cout << turns << " " << sum1 << " " << sum2 << "\n";
    }
    return 0;
}