#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

vector<int> divisors(int x) {
    vector<int> div;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            div.push_back(i);
            if (i != x / i) {
                div.push_back(x / i);
            }
        }
    }
    div.push_back(x);
    return div;
}

vector<int> prime_divisors(int x) {
    vector<int> primes;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            primes.push_back(i);
        }
    }
    if (x > 1) {
        primes.push_back(x);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> div = divisors(n);
        vector<int> primes = prime_divisors(n);

        if (primes.size() == 1) {
            for (int d : div) cout << d << ' ';
            cout << '\n' << 0 << '\n';
            continue;
        } else if (primes.size() == 2) {
            if (primes.front() * primes.back() == n) {
                cout << primes.front() << ' ' << primes.back() << ' ' << n << '\n' << 1 << '\n';
            } else {
                vector<bool> marked(div.size());
                for (int i = 0; i < div.size(); i++) {
                    if (!marked[i] and div[i] % primes.front() == 0 and div[i] != primes.front() * primes.back() and div[i] != n) {
                        cout << div[i] << ' ';
                        marked[i] = true;
                    }
                }
                cout << primes.front() * primes.back() << ' ';
                for (int i = 0; i < div.size(); i++) {
                    if (!marked[i] and div[i] % primes.back() == 0 and div[i] != primes.front() * primes.back() and div[i] != n) {
                        cout << div[i] << ' ';
                        marked[i] = true;
                    }
                }
                cout << n;
                cout << '\n' << 0 << '\n';
            }
            continue;
        }

        vector<set<int>> nums(primes.size());
        vector<int> inbetween;
        vector<bool> marked(div.size());

        for (int j = 0; j < primes.size(); j++) {
            int p = primes[j];
            for (int i = 0; i < div.size(); i++) {
                int d = div[i];
                if (!marked[i] and d % p == 0) {
                    nums[j].insert(d);
                    marked[i] = true;
                }
            }
        }

        for (int i = 0; i < primes.size(); i++) {
            int p1 = primes[i];
            int j = (i + 1) % primes.size();
            int p2 = primes[j];
            nums[min(i, j)].erase(p1 * p2);
            inbetween.push_back(p1 * p2);
        }

        for (int i = 0; i < primes.size(); i++) {
            for (int d : nums[i]) {
                cout << d << ' ';
            }
            cout << inbetween[i] << ' ';
        }
        cout << '\n' << 0 << '\n';
    }
    return 0;
}