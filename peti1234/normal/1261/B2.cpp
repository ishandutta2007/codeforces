#include <bits/stdc++.h>
#define lsb(i) (i&(-i))
using namespace std;
const int c=200002;
vector<pair<int, int>> sz;
vector<pair<pair<int, int>, int> >q;
int n, m, t[c], k[c], ans[c], pos;
void add(int a) {
    while(a<=n) t[a]++, a+=lsb(a);
}
int ask(int a) {
    int ans=0;
    while(a) ans+=t[a], a-=lsb(a);
    return ans;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> k[i];
        sz.push_back({-k[i], i});
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        q.push_back({{a, b}, i});
    }
    sort(sz.begin(), sz.end()), sort(q.begin(), q.end());
    for (int i=0; i<n; i++) {
        add(sz[i].second);
        while(pos<m && q[pos].first.first==i+1) {
            int lo=-1, hi=n+1, mid, ert=q[pos].first.second;
            while(hi-lo>1) {
                mid=(hi+lo)/2;
                if (ask(mid)>=ert) hi=mid;
                else lo=mid;
            }
            ans[q[pos].second]=k[hi];
            pos++;
        }
    }
    for (int i=1; i<=m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}