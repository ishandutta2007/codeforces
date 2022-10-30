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
#include <numeric>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;

const int sz = 5e3 + 5;
ll pa[sz], a[sz], b[sz], pbb[sz], mul[sz], pm[sz];
int n;

ll query(int i, int j) {
    if (i<0 || i>j||j>=n)return 0;
    return pm[j] - (i ? pm[i - 1] : 0);
}

int main() {
    fast;
    cin >> n;
    foru(i, 0, n) {
        cin >> a[i];
        pa[i] = (i ? pa[i - 1] : 0) + a[i];
    }
    foru(i, 0, n) {
        cin >> b[i];
        pbb[i] = (i ? pbb[i - 1] : 0) + b[i];
    }
    foru(i, 0, n) {
        mul[i] =  a[i] * b[i];
        pm[i] = (i ? pm[i - 1] : 0) + mul[i];
    }
    ll tot = 0;
    foru(i, 0, n)tot += (a[i] * b[i]);
    ll bst = tot;
    foru(i, 0, n) {
        ll cr = mul[i];
        for (int j = 1; i - j >= 0 && i + j < n; j++) {
            int l = i - j, r = i + j;
            cr += (a[l] * b[r] + a[r] * b[l]);
            bst = max(bst, cr + query(0, l - 1) + query(r + 1, n - 1));
        }
    }
    foru(i, 0, n-1) {
        ll cr = 0;
        for (int j = 0; i - j >= 0 && i + j + 1< n; j++) {
            int l = i - j, r = i + j + 1;
            cr += (a[l] * b[r] + a[r] * b[l]);
            bst = max(bst, cr + query(0, l - 1) + query(r + 1, n - 1));
        }
    }
    cout << bst;
    return 0;
}