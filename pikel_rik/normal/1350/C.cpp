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

bool prime[200001];
priority_queue<int, vector<int>, greater<>> best[200001];

void sieve(int n = 200000) {
    memset(prime, true, sizeof(prime));

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * (ll)i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 2) {
        cout << (a[0] * (ll)a[1]) / __gcd(a[0], a[1]) << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int temp = a[i];
        for (ll j = 2; j * j <= a[i]; j++) {
            if (prime[j]) {
                int c = 0;
                while (temp % j == 0) {
                    temp /= j;
                    c += 1;
                }

                if (c != 0)
                    best[j].push(c);
            }
        }

        if (temp > 2)
            best[temp].push(1);
    }

    int num = 1;

    for (int i = 2; i <= 2e5; i++) {
        if (best[i].size() == n) {
            best[i].pop();
            num *= pow(i, best[i].top());
        }
        else if (best[i].size() == n - 1) {
            num *= pow(i, best[i].top());
        }
    }

    cout << num;
    return 0;
}