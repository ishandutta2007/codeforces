#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, total;
bool there[N];

int count(int x) {
    cout << "A " << x << endl;
    int cnt;
    cin >> cnt;
    return cnt;
}

int remove(int x) {
    cout << "B " << x << endl;
    for (int i = x; i <= n; i += x) {
        if (there[i]) {
            there[i] = false;
            total--;
        }
    }
    int cnt;
    cin >> cnt;
    return cnt;
}

int answer(int x) {
    cout << "C " << x << endl;
    exit(0);
}

bool prime[N + 1];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    sieve();
    memset(there, true, sizeof(there));

    cin >> n;
    total = n;

    int ans = 1;
    for (int i = 1; i * i <= n; i++) {
        if (prime[i]) {
            remove(i);
        }
    }

    if (count(1) > total) {
        for (int i = 1; i * i <= n; i++) {
            if (prime[i]) {
                int pow = i;
                while (pow <= n and count(pow)) {
                    ans *= i;
                    pow *= i;
                }
            }
        }
        remove(ans);
        for (int i = floor(sqrt(n) + 1); i <= n && ans * ans < n; i++) {
            if (prime[i]) {
                int cnt = 0;
                for (int j = i; j <= n; j += i) {
                    cnt += there[j];
                }
                if (count(i) > cnt) {
                    ans *= i;
                }
            }
        }
    }
    else {
        vector<int> primes;
        for (int i = floor(sqrt(n) + 1); i <= n; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }
        int sq = ceil(sqrt(primes.size()));
        for (int i = 0; i < primes.size(); i += sq) {
            for (int j = i; j < min((int)primes.size(), i + sq); j++) {
                remove(primes[j]);
            }
            if (count(1) > total) {
                for (int j = i; j < min((int)primes.size(), i + sq); j++) {
                    if (count(primes[j])) {
                        ans = primes[j];
                    }
                }
                break;
            }
        }
    }
    answer(ans);
    return 0;
}