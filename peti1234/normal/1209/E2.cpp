#include <bits/stdc++.h>

using namespace std;
const int c=(1<<12), k=13;
int ki[k][c];
vector<int> kell[k][c];
bool fontos[k][c];
int holvan(int a, int b) {
    if (ki[a][b]==b) {
        return b;
    }
    return ki[a][b]=holvan(a, ki[a][b]);
}
void unio(int s, int a, int b) {
    a=holvan(s, a), b=holvan(s, b);
    ki[s][b]=a;
}
int w, n, m, maskdb, t[k][c], regidp[c], ujdp[c], maxi[c], odb;
vector<pair<int, int> > szamok;
bool jooszlop[c];

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=12; i++) {
        int s=(1<<i);
        for (int j=0; j<s; j++) {
            ki[i][j]=j;
        }
        for (int j=0; j<s; j++) {
            int kov=j*2;
            if (kov & s) {
                kov++, kov-=s;
            }
            unio(i, j, kov);
        }
        for (int j=0; j<s; j++) {
            if (holvan(i, j)==j) {
                fontos[i][j]=1;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n >> m;
        maskdb=(1<<n);
        odb=0;
        for (int i=1; i<=m; i++) {
            jooszlop[i]=0;
        }
        szamok.clear();
        for (int i=0; i<n; i++) {
            for (int j=1; j<=m; j++) {
                cin >> t[i][j];
                szamok.push_back({t[i][j], j});
            }
        }
        sort(szamok.rbegin(), szamok.rend());
        for (auto x:szamok) {
            int se=x.second;
            if (!jooszlop[se]) {
                odb++;
                jooszlop[se]=1;
            }
            if (odb==n) {
                break;
            }
        }
        for (int i=0; i<maskdb; i++) {
            regidp[i]=0, ujdp[i]=0;
        }
        for (int j=1; j<=m; j++) {
            if (jooszlop[j]) {
                for (int i=0; i<maskdb; i++) {
                    maxi[i]=0;
                }
                for (int sh=0; sh<n; sh++) {
                    for (int mask=0; mask<maskdb; mask++) {
                        int ert=0;
                        for (int bit=0; bit<n; bit++) {
                            if (mask & (1<<bit)) {
                                ert+=(t[(sh+bit)%n][j]);
                            }
                        }
                        maxi[mask]=max(maxi[mask], ert);
                    }
                }

                for (int i=0; i<maskdb; i++) {
                    if (fontos[n][i]) {
                        for (int resz=i; resz>0; resz=(resz-1)&i) {
                            ujdp[i]=max(ujdp[i], maxi[resz]+regidp[holvan(n, i-resz)]);
                        }
                    }
                }
                for (int i=0; i<maskdb; i++) {
                    regidp[i]=ujdp[i];
                }
            }
        }
        cout << regidp[maskdb-1] << "\n";
    }

    return 0;
}