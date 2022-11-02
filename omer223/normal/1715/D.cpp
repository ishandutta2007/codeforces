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

const int sz = 5e5 + 5, LOG = 30;
vector<pii> adj[sz];
bitset<sz> mustvec;
int f[sz];

int main() {
    fast;
    int n, q;
    cin >> n >> q;
    foru(i, 0, q) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[--a].push_back({ --b,x });
        adj[b].push_back({ a,x });
    }
    foru(i, 0, n) {
        f[i] = -1;
        for (pii ii : adj[i]) {
            if (ii.ff == i)mustvec[i] = 1, f[i] = ii.ss;
        }
    }
    vector<int> a(n, 0);
    foru(j, 0, LOG) {
        vector<bool> must(n, false);
        vector<int> bitarr(n, -1);
        vector<vector<int>> bitadj(n);
        foru(i, 0, n) {
            for (pii ii : adj[i]) {
                int dst = ii.ff, x = ii.ss;
                if ((x >> j) & 1) {
                    if (dst == i) {
                        bitarr[i] = 1;
                        continue;
                    }
                    bitadj[i].push_back(dst);
                }
                else {
                    bitarr[i] = 0;
                }
            }
        }
        foru(i, 0, n) {
            if (bitarr[i] == 1)continue;
            bool has0 = 0;
            for (int dst : bitadj[i]) {
                if (bitarr[dst] == 0) {
                    has0 = 1;
                }
            }
            if (bitarr[i] == -1) {
                bitarr[i] = has0;
            }
            if (bitarr[i] == 0) {
                for (int dst : bitadj[i])must[dst] = 1;
            }
        }
        foru(i, 0, n) {
            if (bitarr[i])a[i] |= (1 << j);
        }
    }
    foru(i, 0, n)cout << a[i] << ' ';
    return 0;
}