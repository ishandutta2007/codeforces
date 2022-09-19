#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, kezd[c], veg[c], cl[c], cnt;
multiset<int> s[2];
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> cl[i] >> kezd[i] >> veg[i];
            sz.push_back({kezd[i], -i}), sz.push_back({veg[i], i});
        }
        sort(sz.begin(), sz.end());
        for (auto a:sz) {
            int id=a.second, p=cl[abs(id)];
            if (id<0) {
                id*=-1;
                s[p].insert(veg[id]);
                if (s[0].size()>0 && s[1].size()>0) {
                    for (int i=0; i<2; i++) {
                        auto it=s[i].end();
                        it--;
                        int x=*it;
                        s[i].clear();
                        s[i].insert(x);
                    }
                }
            } else {
                if (s[p].find(veg[id])!=s[p].end()) {
                    s[p].erase(s[p].find(veg[id]));
                    if (s[1-p].size()==0) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
        s[0].clear(), s[1].clear(), sz.clear(), cnt=0;

    }
    return 0;
}