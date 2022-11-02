#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;




int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b = a;
    map<vector<int>, vector<int>> mem;
    map<vector<int>, int> ctr;
    foru(i, 0, n) {
        foru(j, 0, m)cin >> a[i][j];
        if (!mem.count(a[i]))mem[a[i]] = vector<int>{ i };
        else mem[a[i]].push_back(i);
    }
    bool bad = 0;
    foru(i, 0, n) {
        foru(j, 0, m)cin >> b[i][j];
        if (!mem.count(b[i]) || mem[b[i]].size() == ctr[b[i]]) {
            bad = 1;
            break;
        }
        else {
            b[i].push_back(mem[b[i]][ctr[b[i]]++]);
        }
    }
    if (bad) {
        cout << -1 << '\n';
        return 0;
    }
    else if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<bool> used(m + 1, false), unlocked(n - 1, false);
    vector<int> indeg(m + 1, 0);
    vector<vector<int>> badrow(n - 1), goodrow(m + 1);
    foru(i, 0, n - 1) {
        foru(j, 0, m + 1) {
            if (b[i][j] == b[i + 1][j])continue;
            else if (b[i][j] < b[i + 1][j]) {
                goodrow[j].push_back(i);
            }
            else {
                indeg[j]++;
                badrow[i].push_back(j);
            }
        }
    }
    queue<int> q;
    vector<int> ord;
    foru(j, 0, m + 1) {
        if (!indeg[j]) {
            ord.push_back(j);
            used[j] = 1;
            q.push(j);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : goodrow[x]) {
            if (!unlocked[y]) {
                for (int z : badrow[y]) {
                    indeg[z]--;
                    if (indeg[z] == 0 && !used[z]) {
                        ord.push_back(z);
                        used[z] = 1;
                        q.push(z);
                    }
                }
                unlocked[y] = 1;
            }
        }
    }
    if (ord.size() == m + 1) {
        bool seen = 0;
        vector<int> ans;
        ford(j, m, 0) {
            if (seen)ans.push_back(ord[j] + 1);
            else {
                if (ord[j] == m)seen = 1;
            }
        }
        cout << ans.size() << '\n';
        for (int x : ans)cout << x << ' ';
    }
    else {
        cout << -1 << '\n';
        return 0;
    }
    return 0;
}