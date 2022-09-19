#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, jodb;
vector<int> sz[c], rossz[c];
bool v[c], h[c];
int kerd() {
    int db=0;
    for (int i=1; i<=n; i++) {
        db+=h[i];
    }
    cout << "? " << db << " ";
    for (int i=1; i<=n; i++) {
        if (h[i]) cout << i << " ";
    }
    cout << "\n";
    int x;
    cin >> x;
    return x;
}
void cl() {
    for (int i=1; i<=n; i++) {
        h[i]=0;
    }
}
int cnt=0;
void dfs(int a) {
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            if (2*cnt<jodb) {
                h[x]=1;
                if (!rossz[a][i]) {
                    cnt++;
                }
            }
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    jodb=n-1;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
        rossz[a].push_back(0), rossz[b].push_back(0);
    }
    for (int i=1; i<=n; i++) {
        h[i]=1;
    }
    int cel=kerd();
    cl();
    while (jodb>1) {
        for (int i=1; i<=n; i++) {
            v[i]=0;
        }
        h[1]=1;
        dfs(1);
        int s=kerd();
        for (int i=1; i<=n; i++) {
            for (int j=0; j<sz[i].size(); j++) {
                int x=sz[i][j];
                if (s==cel && (!h[i] || !h[x]) || (s!=cel && h[i] && h[x])) {
                    if (i<x && !rossz[i][j]) {
                        jodb--;
                    }
                    rossz[i][j]=1;
                }
            }
        }
        cnt=0;
        cl();
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            if (!rossz[i][j] && i<x) {
                cout << "! " << i << " " << x << "\n";
            }
        }
    }
    return 0;
}