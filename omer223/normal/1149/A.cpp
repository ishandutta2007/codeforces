#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int n;
int cnts[3];

int main() {
    fast;
    cin >> n;
    int c1 = 0, c2 = 0;
    foru(i, 0, n) {
        int tmp;
        cin >> tmp;
        if (tmp == 1)c1++;
        else c2++;
    }
    if (!c2) {
        while (c1--)cout << 1 << ' ';
        return 0;
    }
    else {
        cout << 2 << ' ';
        c2--;
        if (c1) {
            cout << 1 << ' ';
            c1--;
        }
        foru(i, 0, c2)cout << 2 << ' ';
        foru(i, 0, c1)cout << 1 << ' ';
    }
    return 0;
}