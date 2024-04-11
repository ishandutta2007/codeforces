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
const int N = 1e3 + 5;

int n;
string s;

bool prime[N + 1];
vector<int> primes;

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
    cin.tie(nullptr);

    cin >> s;
    n = s.length();

    sieve();
    for (int i = 1; i <= N; i++) {
        if (prime[i])
            primes.push_back(i);
    }

    vector<int> pos = {1};
    for (int i : primes) {
        if (i <= n and 2 * i > n)
            pos.push_back(i);
    }

    vector<int> cnt(26);
    for (char ch : s) cnt[ch - 'a']++;

    char c = ' ';
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= n - pos.size())
            c = 'a' + i;
    }

    if (c == ' ') {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (binary_search(all(pos), i))
            continue;
        s[i - 1] = c;
    }

    cnt[c - 'a'] -= n - pos.size();

    int ptr = 0;
    for (int j = 0; j < 26; j++) {
        while (cnt[j] and ptr < pos.size()) {
            s[pos[ptr] - 1] = 'a' + j;
            cnt[j]--;
            ptr++;
        }
    }

    cout << "YES\n";
    cout << s;
    return 0;
}