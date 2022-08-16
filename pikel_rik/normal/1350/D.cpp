#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define cnt_l(r, l) cnt_less[r] - cnt_less[l-1]
#define cnt_m(r, l) cnt_more[r] - cnt_less[l-1]
#define cnt(r, l) cnt_k[r] - cnt_k[l-1]
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            a[0] == k ? cout << "yes\n" : cout << "no\n";
            continue;
        }

        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (a[i] < k)
                a[i] = 0;
            else if (a[i] > k)
                a[i] = 2;
            else {
                a[i] = 1;
                flag = true;
            }
        }

        if (!flag) {
            cout << "no\n";
            continue;
        }

        flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n and j - i <= 2; j++) {
                if (a[i] and a[j]) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        flag ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}