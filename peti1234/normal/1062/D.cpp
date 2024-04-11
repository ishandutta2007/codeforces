#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz[100001];
bool v[100001];
long long sum=0;
void dfs(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (a>x) {
            sum+=a/x;
        } else {
            sum+=x/a;
        }
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) {
        for (int j=2*i; j<=n; j+=i) {
            sz[i].push_back(j);
            sz[j].push_back(i);
        }
    }
    dfs(2);
    cout << sum*2 << endl;
    return 0;
}