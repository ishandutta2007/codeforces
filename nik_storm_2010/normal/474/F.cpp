//
//  main.cpp
//  474F
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

map <int, int> base;
vector <int> all[N];
int before[N][LOG], near[N], a[N];

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    for (int i = 1, val = 1, step = 0; i < N; i++) {
        if (val * 2 < i) {
            val *= 2;
            step++;
        }
        near[i] = step;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        before[i][0] = a[i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            before[i][j] = gcd(before[i][j - 1], before[i + (1 << (j - 1))][j - 1]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (base[a[i]] == 0) {
            cnt++;
            base[a[i]] = cnt;
        }
        all[base[a[i]]].push_back(i);
    }
    int q;
    cin >> q;
    for (int t = 1; t <= q; t++) {
        int l, r;
        cin >> l >> r;
        int to = near[r - l + 1];
        int need = gcd(before[l][to], before[r - (1 << to) + 1][to]);
        int x = base[need];
        vector <int>::iterator itl = lower_bound(all[x].begin(), all[x].end(), l);
        if (itl == all[x].end() || *itl > r) {
            cout << r - l + 1 << "\n";
            continue;
        }
        vector <int>::iterator itr = upper_bound(all[x].begin(), all[x].end(), r);
        cout << r - l + 1 - distance(itl, itr) << "\n";
    }
    return 0;
}