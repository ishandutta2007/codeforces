//
//  main.cpp
//  255D
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

ll n, x, y, c;

ll count(ll nx, ll ny, ll cnt) {
    if (nx == 0 || ny == 0) return 0;
    ll res = 0, l, r;
    if (cnt >= nx) {
        ll leng = min(cnt - nx + 1, ny);
        res += leng * nx;
        if (leng == ny) return res;
    }
    l = max(1LL, cnt - ny + 2);
    r = min(nx, cnt + 1);
    res += (l + r) * (r - l + 1) / 2;
    return res;
}

bool ok(ll cnt) {
    ll sum = 1;
    sum += min(x - 1, cnt) + min(y - 1, cnt) + min(n - x, cnt) + min(n - y, cnt);
    if (sum >= c) return true;
    if (cnt < 2) return false;
    sum += count(x - 1, y - 1, cnt - 2);
    sum += count(x - 1, n - y, cnt - 2);
    sum += count(n - x, y - 1, cnt - 2);
    sum += count(n - x, n - y, cnt - 2);
    return (sum >= c);
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y >> c;
    ll l = -1, r = 2 * n;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (ok(m)) r = m; else l = m;
    }
    cout << r << "\n";
    return 0;
}