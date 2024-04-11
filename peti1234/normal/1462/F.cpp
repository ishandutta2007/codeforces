#include <bits/stdc++.h>

using namespace std;

int w, n, maxi, sum, cnt, db[200002];
vector<pair<int, pair<int, int> > > sz;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, maxi=0, sz.clear(), cnt=0;
        for (int i=1; i<=n; i++) {
            db[i]=0;
            int a, b; cin >> a >> b;
            sz.push_back({a, {1, i}}), sz.push_back({b+1, {-1, i}});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<sz.size(); i++) {
            int p=sz[i].second.first, id=sz[i].second.second;
            if (p==1) {
                db[id]=sum-cnt;
                cnt++;
            } else {
                db[id]+=cnt;
                maxi=max(maxi, db[id]);
            }
            sum+=p;
        }
        cout << n-maxi << "\n";
    }
    return 0;
}