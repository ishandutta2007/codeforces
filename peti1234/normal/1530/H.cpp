#include <bits/stdc++.h>

using namespace std;
const int c=15005, k=350, sok=1e5;
int w, n, t[c], dpl[c][k], dpr[c][k], fen[c][k][2];
int lsb(int a) {
    return (a & (-a));
}
int ask(int ert, int s, int id) {
    if (!id) {
        ert=n+1-ert;
    }
    int ans=(id==0 ? sok : -sok);
    while (ert) {
        int p=fen[ert][s][id];
        ans=(id==0 ? min(ans, p) : max(ans, p));
        ert-=lsb(ert);
    }
    return ans;
}
void add(int ert, int s, int id, int val) {
    if (abs(ert)==sok) {
        return;
    }
    if (!id) {
        ert=n+1-ert;
    }
    while (ert<=n) {
        fen[ert][s][id]=(id==0 ? min(fen[ert][s][id], val) : max(fen[ert][s][id], val));
        ert+=lsb(ert);
    }
    return;
}
void init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<k; j++) {
            fen[i][j][0]=sok, dpl[i][j]=sok;
            fen[i][j][1]=-sok, dpr[i][j]=-sok;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        int ans=0;
        for (int spec=0; spec<2; spec++) {
            init();
            if (spec==0) {
                dpl[n][1]=t[n], dpr[n][1]=t[n];
            }
            for (int i=n-1; i>=1; i--) {
                for (int j=2; j<k; j++) {
                    add(t[i+1], j, 0, dpl[i+1][j-1]);
                    add(t[i+1], j, 1, dpr[i+1][j-1]);
                    if (i+j-1<=n) {
                        add(dpr[i+j-1][j-1], j, 0, t[i+j-1]);
                        add(dpl[i+j-1][j-1], j, 1, t[i+j-1]);
                    }
                    dpl[i][j]=ask(t[i], j, 0);
                    dpr[i][j]=ask(t[i], j, 1);
                    if (spec && j==2) {
                        dpl[i][j]=t[i];
                        dpr[i][j]=t[i];
                    }
                    if (dpl[i][j]!=sok || dpr[i][j]!=-sok) {
                        ans=max(ans, j-spec);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}