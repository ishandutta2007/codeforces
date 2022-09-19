#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, p[c];
long long sum, rf[c], q;
bool v[c];
vector<int> sz[c];
void dfs(int a) {
    rf[a]=1, v[a]=true, q+=p[a]%2;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            p[x]=p[a]+1, dfs(x);
            sum+=rf[x]*(n-rf[x]), rf[a]+=rf[x];
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cout << (sum-q*(n-q))/2+q*(n-q) << "\n";
    return 0;
}