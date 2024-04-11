//
// Created by Ormlis on 27.11.2019.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#define pb(el) push_back(el)
using namespace std;

ll MOD = 998244353;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;
int n;

int m, k, t;
vector<int> arr;
vector<pair<pair<int, int>, int>> traps;

int check(int cur) {
    int min_abil = arr[m - cur];
    int max_coord = -1;
    int ans = 0;
    for(auto p: traps) {
        int l = p.first.first;
        int r = p.first.second;
        int d = p.second;
        max_coord = max(max_coord, l - 1);
        if (d > min_abil && r > max_coord) {
            ans += (r - max_coord) * 2;
            max_coord = r;
        }
    }
    return ans + n + 1;
}

void solve() {
    cin >> m >> n >> k >> t;
    arr.resize(m);
    traps.resize(k);
    range(i, m) {
        cin >> arr[i];
    }
    int l, r, d;
    range(i, k) {
        cin >> l >> r >> d;
        traps[i] = {{l, r}, d};
    }
    sort(all(arr));
    arr.push_back(0);
    sort(all(traps));
    int L = 0;
    int R = m + 1;
    while(L + 1 != R) {
        int mid = (R + L) / 2;
        if (check(mid) > t) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << L;
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}