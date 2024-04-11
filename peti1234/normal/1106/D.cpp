#include <bits/stdc++.h>

using namespace std;
priority_queue<int> q;
vector<int> sz[100001];
int n, m;
bool v[100001];
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    q.push(-1);
    while(q.size()>0) {
        int f=-q.top();
        q.pop();
        if (!v[f]) {
            v[f]=true;
            cout << f << " ";
            for (int i=0; i<sz[f].size(); i++) {
                int x=sz[f][i];
                if (!v[x]) {
                    q.push(-x);
                }
            }
        }
    }
    return 0;
}