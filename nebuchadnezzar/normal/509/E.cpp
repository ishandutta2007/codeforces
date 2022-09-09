#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXL = 5e5 + 5;

string s;

long double ssum[MAXL + 1];

long double get_sum(int l, int r) {
    return ssum[r + 1] - ssum[l];
}

bool g(char ch) {
    if (ch == 'I' || ch == 'E' || ch == 'A' || ch == 'O' || ch == 'U' || ch == 'Y') {
        return true;
    }
    return false;
}

int main() {    
    ios_base::sync_with_stdio(false);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;
    int n = szof(s);

    for (int i = 0; i < MAXL; ++i) {
        ssum[i + 1] = ssum[i] + 1 / (long double) (i + 1);
    }

    long double ans = 0;
    long double now = ssum[n];
    for (int i = n - 1; i >= 0; --i) {
        if (g(s[i])) {
            ans += now;
        }
        if (i > 0) {
            now -= get_sum(i, n - 1);
            now += get_sum(n - i, n - 1);
        }
    }

    printf("%.8lf\n", (double) ans);

    return 0;
}