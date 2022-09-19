#include <bits/stdc++.h>

using namespace std;
const int c=505;
int w, n, cnt, db[c][c], t[2*c][c], st[2*c];
bool el[2*c][2*c];
long long ans, mod=998244353;
void torol(int a) {
    cnt--;
    st[a]=-1;
    for (int i=1; i<=n; i++) {
        db[i][t[a][i]]--;
    }
}
void add(int a) {
    cnt--;
    st[a]=1;
    for (int i=1; i<=n; i++) {
        db[i][t[a][i]]--;
    }
    for (int i=1; i<=2*n; i++) {
        if (!st[i] && el[a][i]) {
            torol(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=1, cnt=2*n;
        for (int i=1; i<=2*n; i++) {
            for (int j=1; j<=n; j++) {
                cin >> t[i][j];
                db[j][t[i][j]]++;
                for (int k=1; k<i; k++) {
                    if (t[i][j]==t[k][j]) {
                        el[i][k]=1;
                        el[k][i]=1;
                    }
                }
            }
        }
        while (cnt) {
            bool jo=0;
            int o=0, ert=0;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (db[i][j]==1) {
                        o=i, ert=j;
                    }
                }
                if (ert) {
                    jo=1;
                    break;
                }
            }
            if (jo) {
                for (int i=1; i<=2*n; i++) {
                    if (!st[i] && t[i][o]==ert) {
                        add(i);
                    }
                }
            } else {
                for (int i=1; i<=2*n; i++) {
                    if (!st[i]) {
                        ans*=2, ans%=mod;
                        add(i);
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
        for (int i=1; i<=2*n; i++) {
            if (st[i]==1) {
                cout << i << " ";
            }
        }
        cout << "\n";
        for (int i=1; i<=2*n; i++) {
            for (int j=1; j<=2*n; j++) {
                el[i][j]=0;
            }
            st[i]=0;
        }
    }
    return 0;
}