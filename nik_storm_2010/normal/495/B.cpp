//
//  main.cpp
//  495B
//
//  Created by Sazanovich Nikita on 12/26/14.
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
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "infinity\n";
        return 0;
    }
    if (a < b) {
        cout << "0\n";
        return 0;
    }
    a -= b;
    int ans = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        if (i > b) ans++;
        int j = a / i;
        if (i != j && j > b) ans++;
    }
    cout << ans << "\n";
    return 0;
}