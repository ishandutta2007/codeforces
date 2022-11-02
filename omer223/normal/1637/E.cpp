#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> num2id;
    vector<int> occCnts(n, 0), id2num(n,0);
    foru(i, 0, n) {
        cin >> a[i];
        if (num2id.find(a[i]) == num2id.end()) {
            num2id[a[i]] = num2id.size();
        }
        occCnts[num2id[a[i]]]++;
        id2num[num2id[a[i]]] = a[i];
    }
    vector<vector<int>> adj(n);
    foru(i, 0, m) {
        int x, y;
        cin >> x >> y;
        int id1 = num2id[x], id2 = num2id[y];
        adj[id1].push_back(id2);
        adj[id2].push_back(id1);
    }
    vector<vector<int>> bstInCnt(n + 1);
    foru(id, 0, n) {
        if (occCnts[id] != 0) {
            bstInCnt[occCnts[id]].push_back(id2num[id]);
        }
    }
    vector<int> relevantSizes;
    for (int pos = 1; pos <= n; pos++) {
        if (!bstInCnt[pos].empty()) {
            relevantSizes.push_back(pos);
            sort(bstInCnt[pos].rbegin(), bstInCnt[pos].rend());
        }
    }
    ll bst = 0;
    vector<bool> good(n, 1);
    foru(id, 0, n) {
        ll x = id2num[id], cx = occCnts[id];
        if (x == 0)continue;
        good[id] = 0;
        for (int id2 : adj[id])good[id2] = 0;
        for (int rel : relevantSizes) {
            for (int y : bstInCnt[rel]) {
                int idy = num2id[y];
                if (good[idy]) {
                    bst = max(bst, (x + (ll)y) * (cx + (ll)rel));
                    break;
                }
            }
        }
        good[id] = 1;
        for (int id2 : adj[id])good[id2] = 1;
    }
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}