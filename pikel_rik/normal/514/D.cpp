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
const int N = 1e5;

int n, m, k, a[N][5], best[5];
multiset<int, greater<>> s[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    ll cur_k = k;
    int ptr1 = -1, ptr2 = -1;

    for (int i = 0; i < n; i++) {
        if (accumulate(a[i], a[i] + m, 0) <= k) {
            ptr1 = ptr2 = i;
            cur_k = accumulate(a[i], a[i] + m, 0);
            for (int j = 0; j < m; j++) {
                best[j] = a[i][j];
                s[j].insert(a[i][j]);
            }
            break;
        }
    }

    if (ptr1 == -1) {
        for (int i = 0; i < m; i++) cout << "0 ";
        return 0;
    }

    int len = 1;

    while (true) {
        while (ptr2 < n - 1) {
            ptr2 += 1;
            for (int i = 0; i < m; i++)
                s[i].insert(a[ptr2][i]);

            cur_k = 0;
            for (int i = 0; i < m; i++)
                cur_k += *s[i].begin();

            while (cur_k > k and ptr1 < ptr2) {
                for (int i = 0; i < m; i++)
                    s[i].erase(s[i].find(a[ptr1][i]));

                ptr1 += 1;

                cur_k = 0;
                for (int i = 0; i < m; i++)
                    cur_k += *s[i].begin();
            }

            if (ptr2 - ptr1 + 1 > len and cur_k <= k) {
                for (int i = 0; i < m; i++)
                    best[i] = *s[i].begin();
                len = ptr2 - ptr1 + 1;
            }
        }

        if (ptr2 == n - 1)
            break;
    }

    for (int i = 0; i < m; i++) cout << best[i] << " ";
    cout << "\n";

    return 0;
}