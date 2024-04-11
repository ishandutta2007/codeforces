#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define rep(i, k, n) foru(i, k, n)
#define sz(a) (int)(a.size())

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

const int sz = 5e5;
int cl[sz];

int foo(int l, int r) {
    if (l > r)return 0;
    int tot = 1;
    int cr = l;
    while (cr <= r) {
        int nxt = cl[cr];
        tot += foo(cr + 1, nxt - 1);
        cr = nxt + 1;
    }
    return tot;
}

void solve() {
    string s;
    int n;
    cin >> n >> s;
    stack<int> stk;
    foru(i, 0, 2 * n) {
        if (s[i] == '(')stk.push(i);
        else {
            int x = stk.top(); stk.pop();
            cl[x] = i;
            cl[i] = x;
        }
    }
    cout << foo(0, 2 * n - 1) << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}