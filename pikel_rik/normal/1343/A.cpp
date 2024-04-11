#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define inf INFINITY
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        for (ll i = 2; i <= 32; i++) {
            if (n % ((1LL << i) - 1) == 0) {
                n /= ((1LL << i) - 1);
                break;
            }
        }

        cout << n << "\n";
    }

    return 0;
}