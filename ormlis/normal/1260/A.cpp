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


int main() {
    ios::sync_with_stdio(false);
    //ifstream cin(".in");
    //ofstream cout(".out");
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, s;
    cin >> n;
    range(i, n) {
        cin >> c >> s;
        int x = s / c;
        if (!x) {
            cout << s << '\n';
        } else {
            int y = s % c;
            cout << x * x * (c - y) + (x + 1) * (x + 1) * y << '\n';
        }
    }
    return 0;
}