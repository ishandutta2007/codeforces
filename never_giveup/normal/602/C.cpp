#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

bool q[400][400];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        q[a][b] = 1;
        q[b][a] = 1;
    }
    bool is;
    is = !q[0][n - 1];
    vector<int> bfs;
    bfs.push_back(0);
    int d[400];
    for (int i = 0; i < n; i++)
        d[i] = 1e9;
    d[0] = 0;
    int it = 0;
    while (it < bfs.size()){
        int v = bfs[it];
        it++;
        for (int i = 0; i < n; i++)
            if (q[v][i] == is && d[i] > d[v] + 1){
                d[i] = d[v] + 1;
                bfs.push_back(i);
            }
    }
    if (d[n - 1] == 1e9)
        cout << -1;
    else
        cout << d[n - 1];
}