#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> sz[150001];
bool v[150001];
vector <int> k;
int meret[150001];
void esszeru(int x)
{
    k.push_back(x);
    v[x]=true;
    for (int i=0; i<sz[x].size(); i++) {
        int p=sz[x][i];
        if (!v[p]) {
            esszeru(p);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y);
        sz[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            esszeru(i);
            for (int i=0; i<k.size(); i++) {
                if (sz[k[i]].size()!=k.size()-1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            k.clear();
        }
    }
    cout << "YES" << endl;
    return 0;
}