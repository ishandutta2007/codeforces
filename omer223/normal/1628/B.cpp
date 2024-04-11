#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
    int n;
    cin >> n;
    set<string> mem2, mem3b, mem3;
    bool f = 0;
    foru(i, 0, n) {
        string s, t;
        cin >> s;
        if (s.length() == 1)f = 1;
        else if (s.length() == 2) {
            string t = s;
            reverse(t.begin(), t.end());
            if (mem2.count(t) || mem3b.count(t))f = 1;
            mem2.insert(s);
        }
        else {
            t = s.substr(1, 2);
            reverse(t.begin(), t.end());
            if (mem2.count(t))f = 1;
            mem3b.insert(s.substr(0, 2));
            t = s;
            reverse(t.begin(), t.end());
            if (mem3.count(t))f = 1;
            mem3.insert(s);
        }
        t = s;
        reverse(t.begin(), t.end());
        f |= (t == s);
    }
    cout << (f ? "YES\n" : "NO\n");
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}