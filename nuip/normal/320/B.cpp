#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <map>
using namespace std;

vector<pair<int, int> > interv;

vector<int> visited(200);
int ok;

void dfs(int pos, int goal) {
    int sz = interv.size();
    if(visited[pos]) {
        return;
    }
    visited[pos] = 1;
    int a = interv[pos].first;
    int b = interv[pos].second;
    int c = interv[goal].first;
    int d = interv[goal].second;
    if((c < a && a < d) || (c < b && b < d)) {
        ok = 1;
        return;
    }
    for(int i = 0; i < sz; ++i) {
        c = interv[i].first;
        d = interv[i].second;
        if((c < a && a < d) || (c < b && b < d)) {
            dfs(i, goal);
            if(ok) return;
        }
    }
}

int main() {

    int N;
    char ch;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> ch;
        if(ch == '1') {
            int x, y;
            cin >> x;
            cin >> y;
            interv.emplace_back(x, y);
        }
        else {
            int a, b;
            cin >> a;
            cin >> b;
            --a;
            --b;

            ok = 0;
            fill(visited.begin(), visited.end(), 0);
            dfs(a, b);

            cout << (ok ? "YES" : "NO") << endl;
        }
    }

    return 0;
}