
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
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const string p = "abacaba";

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string os = s;
    foru(i, 0, n - 6) {
        os = s;
        bool bad = 0;
        foru(j, 0, 7) {
            if (os[i + j] == '?')os[i + j] = p[j];
            else if (os[i + j] != p[j]) {
                bad = 1;
                break;
            }
        }
        if (bad)continue;
        foru(j, 0, n)if (os[j] == '?')os[j] = 'z';
        int cnt = 0;
        foru(j, 0, n - 6) {
            if (p == os.substr(j, 7))cnt++;
        }
        if (cnt == 1) {
            cout << "YES\n" << os << '\n';
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}