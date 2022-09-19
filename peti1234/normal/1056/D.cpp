#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz[100001];
int c[100001];
int t[100001];
int sum=0;
int p=1;
void dfs(int a)
{
    if (sz[a].size()==0) {
        c[a]=1;
        return;
    }
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        dfs(x);
        c[a]+=c[x];
    }
    return;
}
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        sz[x].push_back(i);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        //cout << c[i] << endl;
    }
    for (int i=1; i<=n; i++) {
        t[c[i]]++;
    }
    for (int i=1; i<=n; i++) {
        sum+=t[i];
        while(sum>=p) {
            cout << i << " ";
            p++;
        }
    }
    return 0;
}