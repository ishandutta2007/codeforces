//
//  main.cpp
//  498A
//
//  Created by Sazanovich Nikita on 12/25/14.
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

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll r1 = a * x1 + b * y1 + c;
        ll r2 = a * x2 + b * y2 + c;
        if ((r1 < 0 && r2 < 0) || (r1 > 0 && r2 > 0)); else ans++;
    }
    cout << ans << "\n";
    return 0;
}