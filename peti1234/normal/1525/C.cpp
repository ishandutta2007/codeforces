#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, m, ans[c], pos[c];
vector<pair<pair<int, bool>, int> > sz[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            ans[i]=-1;
        }
        sz[0].clear(), sz[1].clear();
        for (int i=1; i<=n; i++) {
            cin >> pos[i];
        }
        for (int i=1; i<=n; i++) {
            bool ir;
            char c;
            cin>> c;
            ir=(c=='L');
            sz[pos[i]%2].push_back({{pos[i], ir}, i});
        }
        for (int par=0; par<2; par++) {
            sort(sz[par].begin(), sz[par].end());
            vector<int> akt;
            for (int j=0; j<sz[par].size(); j++) {
                auto s=sz[par][j];
                int pos=s.first.first, id=s.second;
                bool ir=s.first.second;
                if (akt.size()==0 || !ir) {
                    akt.push_back(j);
                } else {
                    int ut=akt.back();
                    akt.pop_back();
                    auto s2=sz[par][ut];
                    int pos2=s2.first.first, id2=s2.second;
                    bool ir2=s2.first.second;

                    int ert=(pos-pos2)/2+ir2*pos2;
                    ans[id]=ert, ans[id2]=ert;
                }
            }
            int si=akt.size();
            while (si>=2) {
                int x1=akt[si-1], x2=akt[si-2];
                akt.pop_back(), akt.pop_back(), si-=2;

                auto s=sz[par][x1];
                int pos=s.first.first, id=s.second;
                bool ir=s.first.second;

                auto s2=sz[par][x2];
                int pos2=s2.first.first, id2=s2.second;
                bool ir2=s2.first.second;

                int ert=0;
                if (!ir2) {
                    ert=m-pos+(pos-pos2)/2;
                } else {
                    ert=m-(pos-pos2)/2;
                }
                ans[id]=ert, ans[id2]=ert;
            }
        }
        //cout << "valasz: ";
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}