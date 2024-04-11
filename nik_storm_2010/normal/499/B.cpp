//
//  main.cpp
//  499B
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
const int N = 5e3;

string a[N], b[N];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s != a[j] && s != b[j]) continue;
            if (a[j].length() <= b[j].length()) cout << a[j]; else cout << b[j];
            break;
        }
        if (i != n) cout << " ";
    }
    return 0;
}