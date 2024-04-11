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
const int N = 1e6;

int n, m, x[N], cnt[10000001], f[10000001];

bool prime[10000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cnt[x[i]] += 1;
    }

    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= 1e7; i++) {
        if (prime[i]) {
            for (int j = i; j <= 1e7; j += i) {
                prime[j] = false;
                f[i] += cnt[j];
            }
        }
    }

    for (int i = 1; i <= 1e7; i++) {
        f[i] += f[i-1];
    }

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        l = min(l, (int)1e7);
        r = min(r, (int)1e7);

        cout << f[r] - f[l-1] << "\n";
    }

    return 0;
}