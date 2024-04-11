#include <bits/stdc++.h>

using namespace std;
const int c=5000005, k=28;
int n, cnt=1, le[c][2], db[c];
int lep(int pos, int id) {
    if (!le[pos][id]) {
        le[pos][id]=++cnt;
    }
    return le[pos][id];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int id;
        cin >> id;
        if (id==1 || id==2) {
            int x, s=(id==1 ? 1 : -1), pos=1;
            cin >> x;
            db[pos]+=s;
            for (int j=k-1; j>=0; j--) {
                bool kov=(x & (1<<j));
                pos=lep(pos, kov);
                //cout << "vege " << pos << "\n";
                db[pos]+=s;
            }
        } else {
            int x, ert, ans=0, pos=1;
            cin >> x >> ert;
            for (int j=k-1; j>=0; j--) {
                bool kis=(x & (1<<j)), nagy=1-kis, jo=(ert & (1<<j));
                int bal=lep(pos, kis), jobb=lep(pos, nagy);
                //cout << "fontos " << j << " " << bal << " " << jobb << "\n";
                if (jo) {
                    ans+=db[bal];
                    ert-=(1<<j);
                    pos=jobb;
                } else {
                    pos=bal;
                }
                //cout << "vege " << pos << "\n";
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
2
1 4
3 6 3
*/