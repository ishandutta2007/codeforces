#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
const int MAXN = 105;

int n;
string names[MAXN];

vector <int> graph[26];
vector <int> order;

bool used[26];

int dfs(int v) {
    used[v] = true;
    for (int i = 0; i < szof(graph[v]); ++i) {
        if (!used[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    order.puba(v);
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < min(szof(names[i]), szof(names[i + 1])); ++j) {
            if (names[i][j] != names[i + 1][j]) {
                graph[names[i][j] - 'a'].puba(names[i + 1][j] - 'a');
                //cout << names[i][j] << " -> " << names[i + 1][j] << endl;
                flag = true;
                break;
            }
        }
        if (!flag && szof(names[i]) > szof(names[i + 1])) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(bend(order));
    int where[26];

    for (int i = 0; i < 26; ++i) {
        where[order[i]] = i;
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < szof(graph[i]); ++j) {
            if (where[i] >= where[graph[i][j]]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        cout << (char) (order[i] + 'a');
    }
    cout << endl;

    return 0;
}