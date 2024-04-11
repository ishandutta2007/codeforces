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
#include <cstring>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
#define pb(el) push_back(el)
using namespace std;

ll MOD = 998244353;
ll INF = 1e18 * 2;
int INF2 = 1e9 * 2;

void solve() {
    int n;
    cin >> n;
    int used[10];
    map<string, int> arr;
    string s;
    string arr2[n];
    vector<int> ans;
    memset(used, 0, sizeof(used));
    range(i, n) {
        cin >> s;
        arr[s] += 1;
        arr2[i] = s;
        used[s[0] - '0'] = 1;
        if (arr[s] > 1) ans.push_back(i);
    }
    int pos = 0;
    cout << ans.size() << '\n';
    for(auto i: ans) {
        while (used[pos]) pos++;
        char a = '0';
        a += pos;
        arr2[i][0] = a;
        pos++;
    }
    for(const auto& s2: arr2) {
        cout << s2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    range(i, t) {
        solve();
    }
    char a = '0';
    return 0;
}