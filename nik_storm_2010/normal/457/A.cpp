//
//  main.cpp
//  457A
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
const int N = 2e5;

int a[N], b[N];

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    int d1 = int(s1.length()), d2 = int(s2.length());
    for (int i = 0; i < d1; i++) a[d1 - i - 1] = s1[i] - '0';
    for (int i = 0; i < d2; i++) b[d2 - i - 1] = s2[i] - '0';
    for (int i = max(d1, d2) - 1; i > 1; i--) {
        int x = min(a[i], b[i]);
        a[i] -= x;
        b[i] -= x;
        if (a[i] >= 2) {
            cout << ">\n";
            return 0;
        }
        if (b[i] >= 2) {
            cout << "<\n";
            return 0;
        }
        if (a[i] == 1) a[i - 1]++, a[i - 2]++;
        if (b[i] == 1) b[i - 1]++, b[i - 2]++;
    }
    double r1 = (sqrt(5) + 1) / 2 * a[1] + a[0];
    double r2 = (sqrt(5) + 1) / 2 * b[1] + b[0];
    if (r1 == r2) cout << "=\n";
    if (r1 > r2) cout << ">\n";
    if (r1 < r2) cout << "<\n";
    return 0;
}