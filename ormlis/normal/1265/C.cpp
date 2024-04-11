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

void solve() {
    cin >> n;
    int cur = -1, prev = -1;
    int count = 0, first = 0;
    range(i, n) {
        cin >> arr[i];
        if (arr[i] != cur && i < n / 2) {
            count++;
            prev = cur;
            cur = arr[i];
        } else if (arr[i] == cur && i >= n / 2) {
            cur = prev;
            count--;
        }
        if (i < n / 2 && arr[i] == cur && prev == -1) {
            first++;
        }
    }
    int last = -1;
    range(i, n) {
        if (arr[i] == cur) {
            last = i;
        }
    }
    if (count < 3 || first > (last - 1) / 3) {
        cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
        return;
    }
    int second = 0;
    cur = arr[first * 2];
    for (int i = first * 2; i < last + 1; ++i) {
        if (arr[i] != cur) {
            second = i - first;
            break;
        }
    }
    int third = last + 1 - second - first;
    if (first < second && first < third) {
        cout << first << ' ' << second << ' ' << third << '\n';
    } else {
        cout << 0 << ' ' << 0 << ' ' << ' ' << 0 << '\n';
    }
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