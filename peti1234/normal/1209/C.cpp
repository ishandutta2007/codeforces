#include <bits/stdc++.h>

using namespace std;
int q;
vector<pair<int, int> > e, m;
int t[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        int mini=10;
        e.clear();
        m.clear();
        for (int i=1; i<=n; i++) {
            t[i]=1;
        }
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            int x=c-'0';
            while(e.size()>0 && x<e.back().second) {
                m.push_back({e.back().first, e.back().second});
                mini=min(mini, e.back().second);
                t[e.back().first]=2;
                e.pop_back();
            }
            if (x<=mini) {
                e.push_back({i, x});
            } else {
                m.push_back({i, x});
                t[i]=2;
            }
        }
        sort(e.begin(), e.end());
        sort(m.begin(), m.end());
        bool x=true;
        if (m.size()>0 && m[0].second<e.back().second) {
            x=false;
        }
        for (int i=1; i<m.size(); i++) {
            if (m[i].second<m[i-1].second) {
                x=false;
            }
        }
        if (!x) {
            cout << "-";
        } else {
            for (int i=1; i<=n; i++) {
                cout << t[i];
            }
        }
        cout << "\n";
    }
    return 0;
}