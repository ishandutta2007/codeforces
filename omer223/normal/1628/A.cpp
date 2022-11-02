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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    foru(i, 0, n)cin >> a[i];
    vector<int> ans;
    vector<int> sufmex(n);
    set<int> no;
    foru(i, 0, n + 2)no.insert(i);
    ford(i, n - 1, 0) {
        no.erase(a[i]);
        sufmex[i] = *no.begin();
    }
    int i = 0;
    while(i<n) {
        int needmex = sufmex[i];
        set<int> has;
        int crmex = 0;
        foru(j, i, n) {
            has.insert(a[j]);
            while (has.count(crmex))crmex++;
            if (crmex == needmex) {
                ans.push_back(needmex);
                i = j + 1;
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans)cout << x << ' ';
    cout << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}