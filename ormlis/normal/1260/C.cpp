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
int arr[200001];

void solve() {
    ll r, b, k, a;
    cin >> r >> b >> k;
    if (r < b) swap(r, b);
    ll g = __gcd(r, b);
    r /= g;
    b /= g;
    if (r % b != 0 ) {
        a = (r - 2) / b + 1;
    } else {
        a = r / b - 1;
    }
    if (a >= k) {
        cout << "REBEL" << '\n';
    } else {
        cout << "OBEY" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}