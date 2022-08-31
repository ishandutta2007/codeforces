#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5;

vector<int> primes;
bool used[maxN];
void init() {
    for(int i = 2; i < maxN; ++i) {
        if (!used[i]) {
            primes.push_back(i);
            for(int j = i; j < maxN; j += i) used[j] = true;
        }
    }
}

int cnt(int k) {
    int d = 0;
    for(auto &i : primes) {
        if (i * i > k) break;
        while (k % i == 0) {
            k /= i;
            d++;
        }
    }
    if (k != 1) d++;
    return d;
}

void solve() {
    int n; cin >> n;
    map<string, pair<ll, pair<string, string>>> was;
    string last;
    range(i, n) {
        string name; cin >> name;
        last = name;
        string op; cin >> op;
        if (op == ":=") {
            string s; cin >> s;
            int sz = (int)s.size();
            pair<ll, pair<string, string>> kek = {0, {s.substr(0, 3), s.substr(max(0, sz - 3))}};
            if (s.substr(0, 4) == "haha") kek.first++;
            if (s.substr(1, 4) == "haha") kek.first++;
            was[name] = kek;
        } else {
            string a; cin >> a;
            string p; cin >> p;
            string b; cin >> b;
            auto ac = was[a];
            auto bc = was[b];
            pair<ll, pair<string, string>> kek = {0, {"", ""}};
            kek.first = ac.first + bc.first;
            if (ac.second.first.size() < 3) {
                kek.second.first = ac.second.first + bc.second.first;
            } else {
                kek.second.first = ac.second.first;
            }
            kek.second.first = kek.second.first.substr(0, 3);
            if (bc.second.second.size() < 3) {
                kek.second.second = ac.second.second + bc.second.second;
            } else {
                kek.second.second = bc.second.second;
            }
            int sz = kek.second.second.size();
            if (sz > 3) kek.second.second = kek.second.second.substr(sz - 3, 3);
            string s = ac.second.second + bc.second.first;
            for(int j = 0; j + 4 <= (int)s.size(); ++j) {
                if (s.substr(j, 4) == "haha") kek.first++;
            }
            was[name] = kek;
        }
    }
    cout << was[last].first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}