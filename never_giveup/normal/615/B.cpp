#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<int> e[100000];

ll answer = 0;

ll d[100000];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        d[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int)e[i].size(); j++)
            if (e[i][j] > i)
                d[e[i][j]] = max(d[e[i][j]], d[i] + 1);
    for (int i = 0; i < n; i++)
        answer = max(answer, d[i] * (ll)e[i].size());
    cout << answer;
}