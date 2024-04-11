#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, m, p;
bool v[c], h[c];
vector<int> sz[c];
vector<pair<int, int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {int x; cin >> x; s.push_back({x, i});}
    sort(s.begin(), s.end());
    while(p<n) {
        int x=p;
        while(p<n && s[p].first==s[x].first) {
            int se=s[p].second; h[se]=1, p++;
            if (v[se]) {
                cout << -1 << "\n";
                return 0;
            }
            for (int i=0; i<sz[se].size(); i++) v[sz[se][i]]=true;
        }
        for (int i=1; i<=n; i++) if (!v[i] && !h[i]) {
            cout << -1 << "\n";
            return 0;
        }
        for (int i=1; i<=n; i++) v[i]=0;
    }
    for (int i=0; i<n; i++) cout << s[i].second << " ";
    return 0;
}