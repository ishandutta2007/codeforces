#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> data;

const int sz = 1e5;
int n, k;
map<string, vector<int>> mem;
vector<vector<int>> palis;

bool isPali(string s) {
    foru(i, 0, k >> 1) {
        if (s[i] != s[k - i - 1])return 0;
    }
    return 1;
}

int main() {
    fast;
    cin >> n >> k;
    foru(i, 0, n) {
        string s;
        int a;
        cin >> s >> a;
        if (mem.find(s) == mem.end())mem[s] = {a};
        else mem[s].pb(a);
    }
    ll tot = 0;
    while (!mem.empty()) {
        auto x = mem.begin();
        sort(x->second.rbegin(), x->second.rend());
        if (isPali(x->first)) {
            palis.pb(x->second);
        } else {
            string rev = x->first;
            reverse(rev.begin(), rev.end());
            if (mem.find(rev) != mem.end()) {
                vector<int> v = mem[rev];
                sort(v.rbegin(), v.rend());
                mem.erase(rev);
                int i = 0;
                while (i < v.size() && i < x->second.size()) {
                    if (v[i] + x->second[i] > 0)tot += (v[i] + x->second[i]);
                    else break;
                    i++;
                }
            }
        }
        mem.erase(x);
    }
    int paliSize = palis.size();
    vector<int> reg(paliSize, 0);
    ll treg = 0;
    foru(i, 0, paliSize) {
        int j = 0;
        while (j + 1 < palis[i].size() and palis[i][j] + palis[i][j + 1] > 0) {
            reg[i] += palis[i][j] + palis[i][j + 1];
            j+=2;
        }
        treg += reg[i];
    }
    ll bst = treg;
    foru(i, 0, paliSize) {
        ll cr = treg - reg[i] + palis[i][0];
        int j = 1;
        while (j + 1 < palis[i].size() and palis[i][j] + palis[i][j + 1] > 0) {
            cr += palis[i][j] + palis[i][j + 1];
            j+=2;
        }
        bst = max(bst, cr);
    }
    cout << tot + bst << '\n';

    return 0;
}