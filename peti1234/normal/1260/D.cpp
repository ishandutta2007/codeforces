#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int m, n, k, p, t[c], kom[c];
vector<pair<int, pair<int, int> > > sz;
int solve(int a)
{
    for (int i=1; i<c; i++) {
        kom[i]=0;
    }
    for (int i=0; i<sz.size(); i++) {
        if (sz[i].first>t[a]) {
            kom[sz[i].second.first]++;
            kom[sz[i].second.second+1]--;
        }
    }
    int ans=0;
    int db=0;
    for (int i=1; i<c; i++) {
        db+=kom[i];
        if (db>0) {
            ans++;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k >> p;
    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }
    sort(t+1, t+m+1);
    reverse(t+1, t+m+1);
    for (int i=1; i<=k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz.push_back({c, {a, b}});
    }
    int x=0, y=m+1;
    while(y-x>1) {
        int z=(x+y)/2;
        if (n+1+2*solve(z)>p) {
            y=z;
        } else {
            x=z;
        }
    }
    cout << x << "\n";
    return 0;
}