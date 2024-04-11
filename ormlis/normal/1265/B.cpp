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

int n, m;
int arr[200001], arr2[200001];

void solve() {
    cin >> n;
    int x;
    range(i, n) {
        cin >> x;
        arr[i] = x;
        arr2[x] = i;
    }
    int comps = 0;
    for(int i = 1; i <= n; ++i) {
        int j = arr2[i];
        comps++;
        if (j > 0 && arr[j - 1] < i) {
            comps--;
        }
        if (j < n - 1 && arr[j + 1] < i) {
            comps--;
        }
        if (comps == 1) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}