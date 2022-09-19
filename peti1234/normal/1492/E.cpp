#include <bits/stdc++.h>

using namespace std;
const int c=2500002;
int n, m, ans[c], kul[c], pos;
vector<int> h;
vector<vector<int> > t;
bool jo(int pos) {
    bool baj=0;
    int ert=0;
    for (int i=1; i<n; i++) {
        int db=0;
        for (int j=0; j<m; j++) {
            if (j!=pos && t[i][j]!=ans[j]) {
                db++;
            }
        }
        if (db>2) {
            baj=1;
        }
        if (db==2) {
            if (ert && ert!=t[i][pos]) {
                baj=1;
            }
            ert=t[i][pos];
        }
    }
    if (baj) {
        return 0;
    }
    if (!ert) {
        ert=666;
    }
    ans[pos]=ert;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    t.resize(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int x; cin >> x;
            t[i].push_back(x);
            if (x!=t[0][j]) {
                kul[i]++;
                if (kul[i]>=3) {
                    pos=i;
                }
            }
        }
    }
    if (!pos) {
        cout << "Yes\n";
        for (int i:t[0]) {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
    for (int i=0; i<m; i++) {
        if (t[0][i]!=t[pos][i]) {
            h.push_back(i);
        } else {
            ans[i]=t[0][i];
        }
    }
    int si=h.size();
    if (si>4) {
        cout << "No\n";
        return 0;
    }
    for (int i:h) {
        for (int j:h) {
            for (int k:h) {
                ans[k]=t[0][k];
            }
            ans[j]=t[pos][j];
            ans[i]=0;
            if (jo(i)) {
                cout << "Yes\n";
                for (int i=0; i<m; i++) {
                    cout << ans[i] << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}