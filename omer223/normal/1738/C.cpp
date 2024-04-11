#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

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
#include <complex>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const int mx = 200;
int win[2][mx][mx]; //parity of amount of odds, evens, odds

void prec() {
    win[0][0][0] = 1;
    win[1][0][0] = 2;
    for (int e = 0; e < mx; e++) {
        for (int o = 0; o < mx; o++) {
            if (e + o == 0)continue;
            //win0
            int ret = 2;
            if (e) {
                if (o & 1) {
                    if (win[0][e - 1][o] == 2)ret = 1;
                }
                else {
                    if (win[1][e - 1][o] == 2)ret = 1;
                }
            }
            if (o) {
                int neededparity = (1 - (o & 1));
                if (win[neededparity][e][o - 1] == 2)ret = 1;
            }
            win[0][e][o] = ret;
            //win1
            ret = 2;
            if (e) {
                if (o & 1) {
                    if (win[1][e - 1][o] == 2)ret = 1;
                }
                else {
                    if (win[0][e - 1][o] == 2)ret = 1;
                }
            }
            if (o) {
                int neededparity = (o & 1);
                if (win[neededparity][e][o - 1] == 2)ret = 1;
            }
            win[1][e][o] = ret;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int cnt[2]{ 0,0 };
    foru(i, 0, n) {
        int x;
        cin >> x;
        cnt[x & 1]++;
    }
    cout << (win[0][cnt[0]][cnt[1]] == 1 ? "Alice\n" : "Bob\n");
}

int main() {
    fast;
    prec();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}