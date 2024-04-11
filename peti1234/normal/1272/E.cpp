#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], ans[c];
bool v[c];
queue<int> q;
vector<int> sz[c];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int a=i-t[i], b=i+t[i];
        if (a>=1) {
            if (t[i]%2 != t[a]%2) {
                sz[n+1].push_back(i);
            } else {
                sz[a].push_back(i);
            }
        }
        if (b<=n) {
            if (t[i]%2 != t[b]%2) {
                sz[n+1].push_back(i);
            } else {
                sz[b].push_back(i);
            }
        }
    }
    q.push(n+1);
    while (q.size()>0) {
        int id=q.front();
        q.pop();
        for (int x:sz[id]) {
            if (!v[x]) {
                v[x]=1;
                ans[x]=ans[id]+1;
                q.push(x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << (v[i] ? ans[i] : -1) << " ";
    }
    return 0;
}