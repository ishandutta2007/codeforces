#include <bits/stdc++.h>

using namespace std;
int n, sok=1e9+1;
vector<pair<int, int> > xr[3], yr[3];

bool solve(int mid, int ba, int ja, int bf, int jf) {
    //cout << "proba " << mid << " " << ba << " " << ja << " " << bf << " " << jf << "\n";
    //cout << mid-1 << " " << n/3-mid << "\n";
    //return 0;
    if (ba==ja || bf==jf) {
        int xa=-sok, xf=sok;
        if (ba==ja) {
            xa=xr[ba][mid-1].first;
        }
        if (bf==jf) {
            xf=xr[jf][n/3-mid].first;
        }
        if (ba==ja && bf==jf) {
            int db=0, h=3-ba-bf;
            for (auto ert:xr[h]) {
                if (xa<ert.first && ert.first<xf) db++;
            }
            return (db>=mid);
        } else {
            int bal=(ba==ja ? bf : ba), jobb=(ba==ja ? jf : ja);
            int bert=-sok, bdb=0, jert=sok, jdb=0;
            for (auto ert:yr[bal]) {
                if (xa<ert.second && ert.second<xf) {
                    bdb++;
                    bert=ert.first;
                    if (bdb==mid) {
                        break;
                    }
                }
            }
            for (int i=n/3-1; i>=0; i--) {
                auto ert=yr[jobb][i];
                if (xa<ert.second && ert.second<xf) {
                    jdb++;
                    jert=ert.first;
                    if (jdb==mid) {
                        break;
                    }
                }
            }
            if (bdb==mid && jdb==mid && bert<jert) {
                return true;
            }
            return false;
        }
    }


    if (ba==bf || ja==jf) {
        int ya=-sok, yf=sok;
        if (ba==bf) {
            ya=yr[ba][mid-1].first;
        }
        if (ja==jf) {
            yf=yr[jf][n/3-mid].first;
        }
        if (ba==bf && ja==jf) {
            int db=0, h=3-ba-ja;
            for (auto ert:yr[h]) {
                if (ya<ert.first && ert.first<yf) db++;
            }
            return (db>=mid);
        } else {
            int kis=(ba==bf ? ja : ba), nagy=(ba==bf ? jf : bf);
            int kert=-sok, kdb=0, nert=sok, ndb=0;
            for (auto ert:xr[kis]) {
                if (ya<ert.second && ert.second<yf) {
                    kdb++;
                    kert=ert.first;
                    if (kdb==mid) {
                        break;
                    }
                }
            }
            for (int i=n/3-1; i>=0; i--) {
                auto ert=xr[nagy][i];
                if (ya<ert.second && ert.second<yf) {
                    ndb++;
                    nert=ert.first;
                    if (ndb==mid) {
                        break;
                    }
                }
            }
            if (kdb==mid && ndb==mid && kert<nert) {
                return true;
            }
            return false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        c--;
        xr[c].push_back({a, b});
        yr[c].push_back({b, a});
    }
    for (int i=0; i<3; i++) {
        sort(xr[i].begin(), xr[i].end());
        sort(yr[i].begin(), yr[i].end());
    }
    int lo=0, hi=n/3+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        bool jo=0;
        for (int ba=0; ba<3; ba++) {
            for (int ja=0; ja<3; ja++) {
                for (int bf=0; bf<3; bf++) {
                    for (int jf=0; jf<3; jf++) {
                        if (ba==jf || ja==bf) continue;
                        if (solve(mid, ba, ja, bf, jf)) {
                            jo=1;
                        }
                    }
                }
            }
        }
        if (jo) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    cout << 3*lo << "\n";
    return 0;
}
/*
9
0 0 1
0 0 2
0 0 3
1 0 1
-1 0 1
0 1 2
0 1 2
0 -1 3
0 -1 3
*/