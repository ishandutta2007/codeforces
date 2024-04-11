#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, ans, ki[c], be[c], kor[c];
bool v[c];
queue<int> q;
vector<int> sz[c];
int holvan(int a) {
    if (!ki[a]) return a;
    return ki[a]=holvan(ki[a]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        be[b]++;
        a=holvan(a), b=holvan(b);
        if (a!=b) {
            ki[a]=b;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!be[i]) {
            q.push(i);
        }
    }
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        v[a]=true;
        for (auto x:sz[a]) {
            be[x]--;
            if (!be[x]) {
                q.push(x);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            kor[holvan(i)]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (ki[i] || kor[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}