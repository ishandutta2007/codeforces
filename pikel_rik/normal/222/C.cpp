#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

const int N = 1e5 + 5;
const int A = 1e7 + 1;

int n, m, a[N], b[N], cnt[A];
vector<int> primes;
vector<int> div1[N];
vector<int> div2[N];

bool prime[A];
void sieve() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int i = 2; i * i < A; i++) {
        if (prime[i]) {
            for (int j = i * i; j < A; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    sieve();
    for (int i = 1; i < A; i++) {
        if (prime[i])
            primes.push_back(i);
    }

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    for (int i = 0; i < n; i++) {
        for (int j : primes) {
            if (j * j > a[i]) break;

            if (a[i] % j == 0) {
                int c = 0;
                while (a[i] % j == 0) {
                    a[i] /= j;
                    c++;
                    div1[i].push_back(j);
                }

                cnt[j] += c;
            }
        }
        if (a[i] > 1)
            cnt[a[i]]++, div1[i].push_back(a[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j : primes) {
            if (j * j > b[i]) break;

            if (b[i] % j == 0) {
                int c = 0;
                while (b[i] % j == 0) {
                    b[i] /= j;
                    c++;
                    div2[i].push_back(j);
                }

                cnt[j] -= c;
            }
        }
        if (b[i] > 1)
            cnt[b[i]]--, div2[i].push_back(b[i]);
    }

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j : div1[i]) {
            if (cnt[j] > 0)
                temp.push_back(j), cnt[j]--;
        }

        div1[i] = temp;
    }

    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j : div2[i]) {
            if (cnt[j] < 0)
                temp.push_back(j), cnt[j]++;
        }
        div2[i] = temp;
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        int ans = 1;
        for (int j : div1[i])
            ans *= j;
        cout << ans << " ";
    }

    cout << "\n";
    for (int i = 0; i < m; i++) {
        int ans = 1;
        for (int j : div2[i])
            ans *= j;
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}