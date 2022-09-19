#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int w, n, t[c], db0, cnt, db1, rossz, bal[c], baldb, jobb[c];
bool v[c];
vector<pair<int, int> > sz;
priority_queue<int> q;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (!t[i]) {
                db0++;
            }
        }
        for (int i=1; i<=n; i++) {
            if (!t[i]) {
                cnt++;
            } else {
                if (!v[t[i]]) {
                    v[t[i]]=1;
                    db1++;
                }
                if (2*cnt<=db0) {
                    bal[t[i]]=cnt;
                } else {
                    if (!jobb[t[i]]) {
                        jobb[t[i]]=db0-cnt;
                    }
                }
            }
        }
        for (int i=1; i<=n; i++) {
            if (v[i]) {
                sz.push_back({bal[i], i});
            }
        }
        for (int i=1; i<=db0/2; i++) {
            s.insert(-i);
        }
        sort(sz.begin(), sz.end());
        for (auto x:sz) {
            int fi=x.first, se=x.second;
            q.push(jobb[se]);
            baldb++;
            if (baldb>fi) {
                int ert=q.top();
                q.pop();
                baldb--;
                auto lb=s.lower_bound(-ert);
                if (lb!=s.end()) {
                    s.erase(lb);
                } else {
                    rossz++;
                }
            }
        }
        cout << min(db0/2, db1-rossz) << "\n";
        db0=0, cnt=0, db1=0, rossz=0, baldb=0;
        sz.clear(), s.clear();
        while (q.size()>0) {
            q.pop();
        }
        for (int i=1; i<=n; i++) {
            v[i]=0, bal[i]=0, jobb[i]=0, t[i]=0;
        }

    }
    return 0;
}