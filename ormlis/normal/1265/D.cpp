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
int arr[400001], arr2[200001];

vector<int> ans;

void yes() {
    cout << "YES\n";
    range(i, n) {
        cout << ans[i] << ' ';
    }
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    n = a + b + c + d;
    range(i, 4) {
        vector<int> pr{a, b, c, d};
        ans.resize(n);
        ans.assign(n, 0);
        if(!pr[i]) continue;
        int j = 1;
        ans[0] = i;
        pr[i]--;
        int prev = i;
        while (j < n) {
            if (pr[0] && prev == 1) {
                pr[0]--;
                ans[j] = prev = 0;
            } else if(pr[1] && (prev == 0 || prev == 2)) {
                pr[1]--;
                ans[j] = prev = 1;
            } else if(pr[2] && (prev == 1 || prev == 3)) {
                pr[2]--;
                ans[j] = prev = 2;
            } else if(pr[3] && prev == 2) {
                pr[3]--;
                ans[j] = prev = 3;
            } else {
                break;
            }
            j++;
        }
        if(pr[0] + pr[1] + pr[2] + pr[3] == 0) {
            return yes();
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}