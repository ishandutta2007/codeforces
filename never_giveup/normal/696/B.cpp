#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int n;

vector<int> e[maxn];

double q[maxn];

int sz[maxn];

void dfs(int v){
    int sum = sz[v] - 1;
    for (int i = 0; i < e[v].size(); i++)
        q[e[v][i]] = q[v] + 1 + (sum - sz[e[v][i]]) / 2.0, dfs(e[v][i]);
}

void dfs1(int v){
    sz[v] = 1;
    for (int i = 0; i < e[v].size(); i++)
        dfs1(e[v][i]), sz[v] += sz[e[v][i]];
}

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        e[x].push_back(i);
    }
    dfs1(0);
    q[0] = 1;
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << setprecision(20) << q[i] << ' ';
}