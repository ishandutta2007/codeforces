#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (ll i = k; i < n; i++)
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int sz = 3e5;
int n, m, k;
map<string, int> idx;
string p[sz];
vector<int> adj[sz];

inline bool match(const string & pat, const string & txt) {
    foru(i, 0, k) {
        if (pat[i] != txt[i] && pat[i] != '_')
            return 0;
    }
    return 1;
}

vector<int> topo() {
    vector<int> indeg(n, 0);
    foru(i, 0, n) {
        for (int x : adj[i])indeg[x]++;
    }
    queue<int> q;
    foru(i, 0, n) {
        if (!indeg[i])q.push(i);
    }
    vector<int> ret;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ret.push_back(x);
        for (int j : adj[x]) {
            indeg[j]--;
            if (!indeg[j])q.push(j);
        }
    }
    if (ret.size() == n)return ret;
    else return vector<int>{};
}

int main() {
    fast;
    cin >> n >> m >> k;
    foru(i, 0, n) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    bool bad = 0;
    foru(i, 0, m) {
        string str;
        int j;
        cin >> str >> j;
        if (!match(p[--j], str)) bad = 1;
        foru(s, 0, (1 << k)) {
            string tmp = str;
            foru(r, 0, k) {
                if ((s >> r) & 1)tmp[r] = '_';
            }
            if (tmp != p[j] && idx.count(tmp))
                adj[j].push_back(idx[tmp]);
        }
    }
    vector<int> top = topo();
    if (top.empty() || bad)cout << "NO\n";
    else {
        cout << "YES\n";
        foru(i, 0, n)cout << top[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}