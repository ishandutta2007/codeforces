#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, x[c], y[c], ans[c], id1, id2;
map<int, vector<pair<int, int> > > m;
int tav(int a, int b) {
    return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        m[max(x[i], y[i])].push_back({x[i]-y[i], i});
    }
    for (auto p:m) {
        vector<pair<int, int> > v=p.second;
        sort(v.begin(), v.end());
        int a=v[0].second, b=v.back().second;
        ans[a]=tav(b, a)+min(ans[id1]+tav(id1, b), ans[id2]+tav(id2, b));
        ans[b]=tav(a, b)+min(ans[id1]+tav(id1, a), ans[id2]+tav(id2, a));
        id1=a, id2=b;
    }
    cout << min(ans[id1], ans[id2]) << "\n";
    return 0;
}