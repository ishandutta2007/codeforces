#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, m, maxi, f[c], eler[c], visz[c], tav[c], cnt;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    cnt++;
    eler[a]=visz[a]=cnt;
    v[a]=true;
    int tav1=0, tav2=0;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            visz[a]=min(visz[a], visz[x]);
            tav2=max(tav2, tav[x]);
            if (eler[a]<visz[x]) {
                //cout << "el " << a << " " << x << "\n";
                tav2=max(tav2, tav[x]+1);
            }
            if (tav2>tav1) {
                swap(tav1, tav2);
            }
        } else {
            if (x!=f[a]) {
                visz[a]=min(visz[a], eler[x]);
            }
        }
    }
    maxi=max(maxi, tav1+tav2);
    tav[a]=tav1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << maxi << "\n";
    return 0;
}