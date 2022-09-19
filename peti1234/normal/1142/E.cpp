#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, pos[c], be[c], cnt, ans;
vector<int> sz[c];
queue<int> q;
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    cnt++;
    pos[a]=cnt;
}
bool kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    bool s;
    cin >> s;
    return s;
}
void torol(int a) {
    for (int i:sz[a]) {
        if (pos[a]>pos[i]) {
            be[i]--;
            if (!be[i]) {
                q.push(i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j:sz[i]) {
            if (pos[i]>pos[j]) {
                be[j]++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!be[i]) {
            if (!ans) {
                ans=i;
            } else {
                q.push(i);
            }
        }
    }
    while(q.size()) {
        int id=q.front();
        q.pop();
        bool x=kerd(ans, id);
        if (x) {
            torol(id);
        } else {
            torol(ans);
            ans=id;
        }
    }
    cout.flush() << "! " << ans << "\n";
    return 0;
}