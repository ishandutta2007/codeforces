#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, db, n, x[c], y[c], mini, baj;
vector<int> pos;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> a >> b, db=0, baj=0;
        for (int i=0; i<n; i++) {
            x[i+1]=a[i]-'a'+1;
            y[i+1]=b[i]-'a'+1;
            if (x[i+1]>y[i+1]) baj=1;
        }
        if (baj) cout << "-1\n";
        else {
            for (int i=1; i<=20; i++) {
                mini=21, pos.clear();
                for (int j=1; j<=n; j++) if (x[j]==i && x[j]!=y[j]) mini=min(mini, y[j]), pos.push_back(j);
                if (pos.size()>0) {
                    db++;
                    for (int i=0; i<pos.size(); i++) x[pos[i]]=mini;
                }
            }
            cout << db << "\n";
        }
    }
    return 0;
}