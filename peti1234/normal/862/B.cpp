#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> sz[100001];
bool v[100001];
int k[100001];
void melysegi(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            k[x]=k[a]+1;
            melysegi(x);
        }
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
    }
    melysegi(1);
    long long p=0;
    for (int i=1; i<=n; i++) {
        if (k[i]%2==0) {
            p++;
        }
    }
    cout << p*(n-p)-n+1 << endl;
    return 0;
}