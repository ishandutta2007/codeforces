
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
#include <math.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


void solve() {
    string s;
    int n;
    cin >> n >> s;
    string ret = "";
    ret += s[0];
    foru(i, 1, n) {
        if (s[i] < s[i - 1])ret.push_back(s[i]);
        else if (s[i] == s[i - 1] && i != 1)ret.push_back(s[i]);
        else break;
    }
    string ans = ret;
    reverse(ans.begin(), ans.end());
    cout << ret + ans << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}