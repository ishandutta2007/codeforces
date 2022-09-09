#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
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
typedef pair <int, int> pii;
const LL MOD = 1e9 + 7;

int n;
string s;

int chti(char ch) {
    if (ch == 'A') {
        return 0;
    }
    if (ch == 'T') {
        return 1;
    }
    if (ch == 'G') {
        return 2;
    }
    if (ch == 'C') {
        return 3;
    }
    assert(false);
}

int numh[4];

LL mpow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    LL ret = mpow(a, b / 2);
    ret = (ret * ret) % MOD;
    if (b & 1) {
        ret = (ret * a) % MOD;
    }
    return ret;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        numh[chti(s[i])]++;
    }

    int best = -1, numb = 0;

    for (int i = 0; i < 4; ++i) {
        if (best < numh[i]) {
            best = numh[i];
            numb = 0;
        }
        if (best == numh[i]) {
            ++numb;
        }
    }

    //cout << numb << endl;
    cout << mpow(numb, n) << endl;

    return 0;
}