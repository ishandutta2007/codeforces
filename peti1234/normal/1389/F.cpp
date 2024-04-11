#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, p1, p2, veg[c], ans;
vector<pair<int, pair<int, int> > > sz;
set<pair<int, int> > x, y;
bool v[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int s, f, p;
        cin >> s >> f >> p;
        veg[i]=f;
        sz.push_back({s, {-i, p}}), sz.push_back({f, {i, p}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<2*n; i++) {
        int id=sz[i].second.first, p=sz[i].second.second;
        if (id<0) {
            if (p==1) x.insert({veg[-id], -id});
            else y.insert({veg[-id], -id});
        } else if (!v[id]) {
            v[id]=1;
            if (p==1) {
                while(y.size()>0) {
                    auto it=y.begin();
                    pair<int, int> f=*it;
                    if (v[f.second]) y.erase(f);
                    else break;
                }
                if (y.size()>0) {
                    auto it=y.begin();
                    pair<int, int> f=*it;
                    y.erase(f), ans++;
                    v[f.second]=1;
                }
            } else {
                while(x.size()>0) {
                    auto it=x.begin();
                    pair<int, int> f=*it;
                    if (v[f.second]) x.erase(f);
                    else break;
                }
                if (x.size()>0) {
                    auto it=x.begin();
                    pair<int, int> f=*it;
                    x.erase(f), ans++;
                    v[f.second]=1;
                }
            }
        }
    }
    cout << n-ans << "\n";
    return 0;
}