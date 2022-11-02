#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

struct Node {
    int nxt[2];
    int mx[2]; //a
    Node() {
        nxt[0] = nxt[1] = -1;
        mx[0] = mx[1] = 0;
    }
};

const int sz = 3e5 + 5, LOGA = 30;
int n, a[sz], dp[sz];
vector<Node> trie(1);

int traverse(int x, int idx) {
    int cur = 0, bst = 0;
    ford(j, LOGA - 1, 0) {
        int xb = ((x >> j) & 1),
            ib = ((idx >> j) & 1);
        if (trie[cur].nxt[xb ^ ib ^ 1] != -1) {
            bst = max(bst, trie[trie[cur].nxt[xb ^ ib ^ 1]].mx[ib ^ 1]);
        }
        if (trie[cur].nxt[xb ^ ib] != -1) {
            cur = trie[cur].nxt[xb ^ ib];
        }
        else {
            break;
        }
    }
    return bst + 1;
}

void insert(int idx) {
    int cur = 0;
    ford(j, LOGA - 1, 0) {
        int xb = ((a[idx] >> j) & 1),
            ib = ((idx >> j) & 1);
        if (trie[cur].nxt[xb ^ ib] == -1) {
            trie[cur].nxt[xb^ib] = trie.size();
            trie.push_back(Node());
        }
        cur = trie[cur].nxt[xb ^ ib];
        chkmax(trie[cur].mx[xb], dp[idx]);
    }
}

void solve() {
    trie.clear();
    trie.push_back(Node());
    cin >> n;
    foru(i, 0, n)cin >> a[i];
    ford(i, n - 1, 0) {
        dp[i] = traverse(a[i], i);
        insert(i);
    }
    int bst = 0;
    foru(i, 0, n)chkmax(bst, dp[i]);
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
   
    return 0;
}