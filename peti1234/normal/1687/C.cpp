#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, m;
long long sum, a[c], b[c];
vector<pair<int, int> > sz[c];
queue<pair<int, int> > q;
set<int> s;
void cl(int a) {
    s.erase(a);
    for (auto x:sz[a]) {
        int f=x.first, g=x.second;
        if (s.find(f)==s.end() && s.find(g)==s.end()) {
            q.push({f, g});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        for (int i=1; i<=m; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            sz[l].push_back({l, r});
            sz[r].push_back({l, r});
        }
        for (int i=0; i<=n; i++) {
            s.insert(i);
        }
        cl(0);
        for (int i=1; i<=n; i++) {
            sum+=a[i]-b[i];
            if (!sum) {
                cl(i);
            }
        }
        while (q.size()>0) {
            int l=q.front().first, r=q.front().second;
            q.pop();
            vector<int> t;
            for (auto it=s.lower_bound(l); it!=s.upper_bound(r); it++) {
                t.push_back(*it);
            }
            for (auto x:t) {
                cl(x);
            }
        }
        cout << (s.size()==0 ? "YES" : "NO") << "\n";

        for (int i=0; i<=n; i++) {
            sz[i].clear();
        }
        s.clear();
        sum=0;
    }
    return 0;
}