#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, kis[c], eldb[c], gr[c], f[c], spec[c], db[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    kis[a]=a;
    for (auto x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            eldb[a]+=eldb[x];
            gr[a]^=gr[x];
            kis[a]=min(kis[a], kis[x]);
        }
    }
    for (auto x:sz[a]) {
        if (f[a]!=x && kis[a]<kis[x]) {
            spec[kis[a]]^=gr[x]^eldb[x];
            spec[kis[x]]^=gr[x]^eldb[x];
        }
    }
    gr[a]++, eldb[a]++;
    eldb[a]%=2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    int res=1-n%2;
    for (int i=1; i<=n; i++) {
        res^=spec[i]^db[i];
        cout << (res==0 ? 2 : 1);
    }
    cout << "\n";
    return 0;
}