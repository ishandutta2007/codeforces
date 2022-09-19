#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, p, maxi, mini;
vector<int> sz[c];
vector<int> inv[c];
queue<pair<int, int> > f;
vector<int> q;
int dist[c], jo[c];
bool v[c];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[b].push_back(a);
        inv[a].push_back(b);
    }
    cin >> p;
    for (int i=0; i<p; i++) {
        int a;
        cin >> a;
        q.push_back(a);
    }
    f.push({q.back(), 0});
    while(f.size()>0) {
        int fi=f.front().first, se=f.front().second;
        f.pop();
        if (!v[fi]) {
            dist[fi]=se, v[fi]=true;
            for (int i=0; i<sz[fi].size(); i++) {
                int x=sz[fi][i];
                if (!v[x]) f.push({x, se+1});
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<inv[i].size(); j++) {
            if (dist[inv[i][j]]+1==dist[i]) jo[i]++;
        }
    }
    for (int i=1; i<p; i++) {
        if (dist[q[i]]>=dist[q[i-1]]) maxi++, mini++;
        else if (jo[q[i-1]]>1) maxi++;
    }
    cout << mini << " " << maxi << "\n";
    return 0;
}