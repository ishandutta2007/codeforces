//
//  main.cpp
//  496D
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
const int INF = 2e9;

int a[N], place[N], to[3][N];
vector <int> c1, c2;
vector <pii> ans;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            place[i] = int(c1.size());
            c1.push_back(i);
        }
        else {
            place[i] = int(c2.size());
            c2.push_back(i);
        }
    }
    to[1][n + 1] = to[2][n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        to[1][i] = to[1][i + 1];
        to[2][i] = to[2][i + 1];
        to[a[i]][i] = i;
    }
    for (int t = 1; t <= n; t++) {
        int i = 1, k1 = 0, k2 = 0;
        bool ok = true, first = false;
        while (i <= n) {
            int n1 = to[1][i];
            if (n1 != INF && place[n1] + t - 1 < c1.size()) n1 = c1[place[n1] + t - 1]; else n1 = INF;
            int n2 = to[2][i];
            if (n2 != INF && place[n2] + t - 1 < c2.size()) n2 = c2[place[n2] + t - 1]; else n2 = INF;
            if (n1 == INF && n2 == INF) {
                ok = false;
                break;
            }
            if (n1 < n2) {
                i = n1 + 1;
                k1++;
                first = true;
            }
            else {
                i = n2 + 1;
                k2++;
                first = false;
            }
        }
        if (!ok) continue;
        if ((k1 > k2 && first) || (k1 < k2 && !first)) ans.push_back(make_pair(max(k1, k2), t));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}