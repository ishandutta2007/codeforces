#include <bits/stdc++.h>

using namespace std;
const int c=200002, k=20;
long long n, ert[c], fel[c][k], tav[c][k], kom[c];
vector<int> sz[c], s[c];
void dfs(int a) {
    kom[a]++;
    long long pos=a, val=ert[a];
    for (int i=1; i<k; i++) {
        int s=fel[a][i-1];
        fel[a][i]=fel[s][i-1];
        tav[a][i]=tav[a][i-1]+tav[s][i-1];
    }
    for (int i=k-1; i>=0; i--) {
        if (fel[a][i] && val>=tav[pos][i]) {
            val-=tav[pos][i];
            pos=fel[pos][i];
        }
    }
    kom[fel[pos][0]]--;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i], y=s[a][i];
        fel[x][0]=a, tav[x][0]=y;
        dfs(x);
        kom[a]+=kom[x];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=2; i<=n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(i), s[a].push_back(b);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        cout << kom[i]-1 << " ";
    }
    cout << "\n";
    return 0;
}