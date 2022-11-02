#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;

vector<int> getBase(vector<int> a) {
    const int LOG = 30;
    vector<int> basis(LOG, -1);
    foru(i, 0, a.size()) {
        int msk = (1 << (LOG - 1));
        ford(j, LOG - 1, 0) {
            if (a[i] & msk) {
                if (basis[j] == -1) {
                    basis[j] = a[i]; break;
                }
                else
                    a[i] ^= basis[j];
            }
            msk >>= 1;
        }
    }
    return basis;
}

int main() {
    fast;
    int n, x=0;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n) {
        int tmp;
        cin >> tmp; x ^= tmp; a[i] = x;
    }
    if (!x) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> b = getBase(a);
    int cnt = 0;
    for (int x : b)cnt += (x != -1);
    cout << cnt;
    return 0;
}