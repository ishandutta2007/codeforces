#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sol;
int n, m, db, kezd[c], veg[c];
bool v[c];
vector<pair<int, pair<int, int> > >sz;
priority_queue<pair<int, int> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> kezd[i] >> veg[i];
        sz.push_back({kezd[i], {-1, i}});
        sz.push_back({veg[i], {1, i}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int p=sz[i].second.first, id=sz[i].second.second;
        if (p==1) {
            if (!v[id]) {
                v[id]=1;
                db--;
            }
        } else {
            db++;
            q.push({veg[id], id});
            if (db>m) {
                while(v[q.top().second]) q.pop();
                int x=q.top().second;
                sol.push_back(x), q.pop(), v[x]=1;
                db--;
            }
        }
    }
    sort(sol.begin(), sol.end());
    int si=sol.size();
    cout << si << "\n";
    for (int i=0; i<si; i++) cout << sol[i] << " ";
    cout << "\n";
    return 0;
}