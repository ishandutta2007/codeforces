#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, k, cnt, db[c], l[c];
vector<int> sz[c];
queue<int> q;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, cnt=0;
        for (int i=1; i<=n; i++) db[i]=0, l[i]=0, v[i]=0, sz[i].clear();
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        for (int i=1; i<=n; i++) {db[i]=sz[i].size(); if (db[i]==1) l[sz[i][0]]++;}
        for (int i=1; i<=n; i++) if (l[i]>=k) q.push(i);
        while(q.size()) {
            int a=q.front();
            q.pop();
            if (!v[a] && k>1) {
                int x=l[a]/k;
                cnt+=x, db[a]-=x*k, l[a]-=x*k;
                if (db[a]==1) {
                    v[a]=1;
                    for (int i=0; i<sz[a].size(); i++) {
                        int x=sz[a][i];
                        if (!v[x]) {
                            l[x]++;
                            if (l[x]==k) q.push(x);
                        }
                    }
                }
            }
        }
        if (k==1) cnt=n-1;
        cout << cnt << "\n";
    }
    return 0;
}