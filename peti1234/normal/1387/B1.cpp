#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int s, n, w[c];
vector<int> sz[c];
bool v[c];
bool d(int a) {
    v[a]=true;
    int el=a;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x] && !d(x)) w[el]=x, el=x;
    }
    if (el!=a) {w[el]=a, s-=2; return 1;}
    return 0;
}
int main()
{
    cin >> n, s=2*n;
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        sz[x].push_back(y), sz[y].push_back(x);
    }
    for (int i=1; i<=n; i++) if (sz[i].size()==1) {d(sz[i][0]); break;}
    cout << s << "\n";
    for (int i=1; i<=n; i++) cout << w[i] << " ";
    return 0;
}