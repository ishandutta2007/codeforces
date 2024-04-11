#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, t[c], db[c], cnt;
long long sum;
map<int, int> m;
vector<pair<int, pair<int, int> > > sz;
int lsb(int a) {
    return (a & (-a));
}
void add(int a) {
    while (a<=n) {
        db[a]++;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=db[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        m[t[i]]++;
        sz.push_back({m[t[i]], {0, i}});
    }
    m.clear();
    for (int i=n; i>=1; i--) {
        m[t[i]]++;
        sz.push_back({m[t[i]], {1, i}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<2*n; i++) {
        int cs=sz[i].second.first, id=sz[i].second.second;
        if (cs==1) {
            cnt++;
            add(id);
        } else {
            sum+=cnt-ask(id);

        }
    }
    cout << sum << "\n";
    return 0;
}