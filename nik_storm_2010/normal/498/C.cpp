//
//  main.cpp
//  498C
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
typedef pair <int, pii> piii;
const int N = 4e3;

vector <int> edges[N];
vector <piii> base[N];
bool used[N];
int last[N];

bool ok(int x) {
    if (used[x]) return false;
    used[x] = true;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (last[to] == -1 || ok(last[to])) {
            last[to] = x;
            return true;
        }
    }
    return false;
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            if (a % j != 0) continue;
            int all = 0;
            while (a % j == 0) all++, a /= j;
            base[i].push_back(make_pair(j, make_pair(cnt + 1, cnt + all)));
            cnt += all;
        }
        if (a != 1) {
            base[i].push_back(make_pair(a, make_pair(cnt + 1, cnt + 1)));
            cnt++;
        }
    }
    for (int c = 1; c <= m; c++) {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 0) swap(x, y);
        for (int i = 0; i < base[x].size(); i++) for (int j = 0; j < base[y].size(); j++) {
            if (base[x][i].first != base[y][j].first) continue;
            for (int c1 = base[x][i].second.first; c1 <= base[x][i].second.second; c1++)
                for (int c2 = base[y][j].second.first; c2 <= base[y][j].second.second; c2++)
                    edges[c1].push_back(c2);
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) last[i] = -1;
    for (int i = 1; i <= cnt; i++) {
        memset(used, false, sizeof(used));
        if (ok(i)) ans++;
    }
    cout << ans << "\n";
    return 0;
}