
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int sz = 1e6 + 5;
int n;
int gcdarr[sz];
bitset<sz> found;

int main() {
    fast;
    cin >> n;
    foru(i, 0, n) {
        int y;
        cin >> y;
        found[y] = 1;
    }
    for (int y = 1; y <= 1e6; y++) {
        for (int z = y; z <= 1e6; z += y) {
            if (found[z])
                gcdarr[y] = gcd(gcdarr[y], z);
        }
    }
    int cnt = 0;
    for (int y = 1; y <= 1e6; y++)cnt += (gcdarr[y] == y);
    cout << cnt - n << '\n';
    return 0;
}