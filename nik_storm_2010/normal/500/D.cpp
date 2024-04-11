//
//  main.cpp
//  500D
//
//  Created by Sazanovich Nikita on 1/6/15.
//  Copyright (c) 2015 Sazanovich Nikita. All rights reserved.
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
const int N = 1e5 + 10;

vector <pii> edges[N];
int up[N], down[N], father[N], a[N], b[N], l[N], n;
ll sum;

void dfs(int x, int last) {
    down[x] = 1;
    father[x] = last;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i].first;
        int l = edges[x][i].second;
        if (to == last)
            continue;
        dfs(to, x);
        down[x] += down[to];
        sum += 1LL * l * down[to] * (n - down[to]);
    }
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout << setprecision(6) << fixed;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i] >> b[i] >> l[i];
        edges[a[i]].push_back(make_pair(b[i], l[i]));
        edges[b[i]].push_back(make_pair(a[i], l[i]));
    }
    int coef = 6 * (n - 2);
    double all = 1LL * n * (n - 1) * (n - 2);
    all /= coef;
    dfs(1, 0);
    for (int i = 1; i < n; i++)
        if (father[a[i]] != b[i])
            swap(a[i], b[i]);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int nom, weight;
        cin >> nom >> weight;
        int delta = l[nom] - weight;
        l[nom] = weight;
        sum -= 1LL * delta * down[a[nom]] * (n - down[a[nom]]);
        cout << (sum + 0.0) / all << "\n";
    }
    return 0;
}