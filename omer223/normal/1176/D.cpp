
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int N = 2750131, primeAmt = 199999;
int lp[N + 1], ord[N + 1];
vector<int> pr;


void prec() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            ord[i] = pr.size();
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

const int sz = 5e5;
int n;
multiset<int, greater<int>> s, a, b;

int main() {
    fast;
    prec();
    cin >> n;
    foru(i, 0, 2 * n) {
        int x;
        cin >> x;
        s.insert(x);
    }
    bool bad = 0;
    while (!s.empty() && !bad) {
        auto x = s.begin();
        int y = *x;
        s.erase(x);
        if (lp[y] == y) {
            if (ord[y] <= primeAmt) {
                b.insert(y);
                auto z = s.find(ord[y]);
                if (lp[ord[y]] == ord[y] && ord[y] != 1 && z != s.end()) {
                    a.insert(*z);
                    s.erase(z);
                }
                else {
                    bad = 1;
                    break;
                }
            }
            else {
                bad = 1;
                break;
            }
        }
        else {
            a.insert(y);
            int bstdiv = y / lp[y];
            auto z = s.find(bstdiv);
            if (z != s.end()) {
                b.insert(*z);
                s.erase(z);
            }
            else {
                bad = 1;
                break;
            }
        }
    }
    if (bad)cout << -1 << '\n';
    else {
        for (int x : a)cout << x << ' ';
        cout << '\n';
    }
    return 0;
}