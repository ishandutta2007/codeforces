//
//  main.cpp
//  487B
//
//  Created by Sazanovich Nikita on 12/27/14.
//  Copyright (c) 2014 Sazanovich Nikita. All rights reserved.
//

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2e5;
const int LOG = 20;
const int INF = 2e9;

int tree[4 * N], a[N], mmin[N][LOG], mmax[N][LOG], need[N], s;

void modify(int i, int l, int r, int x, int d) {
    if (l == r) {
        tree[i] = d;
        return;
    }
    int m = (l + r) / 2;
    if (x <= m)
        modify(i * 2, l, m, x, d);
    else
        modify(i * 2 + 1, m + 1, r, x, d);
    tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int get(int i, int l, int r, int ql, int qr) {
    if (l == ql && r == qr)
        return tree[i];
    int m = (l + r) / 2, res = INF;
    if (ql <= m)
        res = min(res, get(i * 2, l, m, ql, min(qr, m)));
    if (m < qr)
        res = min(res, get(i * 2 + 1, m + 1, r, max(ql, m + 1), qr));
    return res;
}

bool good(int l, int r) {
    int to = need[r - l + 1];
    int v1 = min(mmin[l][to], mmin[r - (1 << to) + 1][to]);
    int v2 = max(mmax[l][to], mmax[r - (1 << to) + 1][to]);
    return (v2 - v1 <= s);
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 4 * N; i++)
        tree[i] = INF;
    int n, leng;
    cin >> n >> s >> leng;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int val = 1, step = 0;
    for (int i = 1; i <= n; i++) {
        if (val * 2 < i) {
            val *= 2;
            step++;
        }
        need[i] = step;
    }
    for (int i = 1; i <= n; i++)
        mmin[i][0] = mmax[i][0] = a[i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
        }
    modify(1, 0, n, 0, 0);
    for (int i = leng; i <= n; i++) {
        if (!good(i - leng + 1, i))
            continue;
        int l = -1, r = i - leng;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (good(m + 1, i))
                r = m;
            else
                l = m;
        }
        int res = get(1, 0, n, r, i - leng);
        if (res == INF)
            continue;
        modify(1, 0, n, i, res + 1);
    }
    int ans = get(1, 0, n, n, n);
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
    return 0;
}