//
//  main.cpp
//  494B
//
//  Created by Sazanovich Nikita on 12/30/14.
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
const int N = 3e5;
const int MOD = 1e9 + 7;

int p[N], f[N], sum[N];

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int ds = (int)s.length(), dt = (int)t.length();
    string help = t + "$" + s;
    for (int i = 1; i < help.length(); i++) {
        int k = p[i - 1];
        while (k > 0 && help[k] != help[i])
            k = p[k - 1];
        if (help[k] == help[i])
            k++;
        p[i] = k;
    }
    int last = -1;
    for (int i = dt - 1; i < ds; i++) {
        if (p[i + dt + 1] == dt)
            last = i;
        if (last == -1)
            continue;
        f[i] = last - dt + 2;
        if (i != 0)
            f[i] += f[i - 1];
        if (last != dt - 1)
            f[i] += sum[last - dt];
        f[i] %= MOD;
        sum[i] = (i == 0 ? 0 : sum[i - 1]);
        sum[i] = (sum[i] + f[i]) % MOD;
    }
    cout << f[ds - 1] << "\n";
    return 0;
}