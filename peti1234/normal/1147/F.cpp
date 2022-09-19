#include <bits/stdc++.h>

using namespace std;
const int c=105;
int w, n, t[c][c], par[c];
void calc(int a) {
    int ert=0;
    for (int i=n+1; i<=2*n; i++) {
        if (t[a][i]>t[a][par[a]] && (ert==0 || t[a][i]<t[a][ert])) {
            ert=i;
        }
    }
    par[a]=ert;
    if (!par[ert]) {
        par[ert]=a;
    }
    int x=par[ert];
    if (x!=a) {
        if (t[x][ert]>t[a][ert]) {
            calc(a);
        } else {
            par[ert]=a;
            calc(x);
        }
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            for (int j=n+1; j<=2*n; j++) {
                cin >> t[i][j];
            }
        }
        cout.flush() << "B" << endl;
        char c;
        cin >> c;
        int pos;
        cin >> pos;
        if ((c=='I') != (pos<=n)) {
            for (int i=1; i<=n; i++) {
                for (int j=n+1; j<=2*n; j++) {
                    t[i][j]=n*n+1-t[i][j];
                }
            }
        }
        for (int i=1; i<=n; i++) {
            calc(i);
        }
        while (pos!=-1) {
            cout.flush() << par[pos] << endl;
            cin >> pos;
        }
        for (int i=1; i<=2*n; i++) {
            par[i]=0;
        }
    }
    return 0;
}