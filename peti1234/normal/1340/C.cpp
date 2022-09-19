#include <bits/stdc++.h>

using namespace std;
int tav[10002][1002], t[10002], sok=1e9+1;
bool v[10002][1002];
// tav[i][j] az i. szigetre a j. pillanatban milyen gyorsan lehet eljutni
// v[i][j] el lehet-e jutni tav[i][j]-be
deque<pair<int, int> > q;
int m, n, mod, r, mini;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> m >> n, mini=sok;
    for (int i=0; i<n; i++) cin >> t[i];
    sort(t, t+n);
    cin >> mod >> r;
    // mod zld hossza
    for (int i=0; i<n; i++) {
        for (int j=0; j<mod; j++) {
            tav[i][j]=sok;
            // alapbl mindegyik vgtelen
        }
    }
    // 0-1 szlessgi bejrs
    q.push_back({0, 0}), tav[0][0]=0;
    while(q.size()>0) {
        int id=q.front().first, ert=q.front().second;
        // id szm sziget az ert pillanatban
        q.pop_front();
        if (!v[id][ert]) {
            v[id][ert]=1;
            if (id!=0) {
                // a sorban az eltte lvre prblok lpni
                int ut=t[id]-t[id-1], x=ert+ut, y=x%mod;
                if (x<=mod) {
                    // ha x>mod, akkor nem lehet lpni
                    if (y!=0) {
                        // 0 sly l
                        q.push_front({id-1, y});
                        tav[id-1][y]=min(tav[id-1][y], tav[id][ert]);
                    }
                    else {
                        // 1 sly l
                        q.push_back({id-1, y});
                        tav[id-1][y]=min(tav[id-1][y], tav[id][ert]+1);
                    }
                }
            }
            if (id+1<n) {
                // a kvetkez szmra akarok lpni
                int ut=t[id+1]-t[id], x=ert+ut, y=x%mod;
                // ugyanaz mint a 34. sortl
                if (x<=mod) {
                    if (y!=0) {
                        q.push_front({id+1, y});
                        tav[id+1][y]=min(tav[id+1][y], tav[id][ert]);
                    }
                    else {
                        q.push_back({id+1, y});
                        tav[id+1][y]=min(tav[id+1][y], tav[id][ert]+1);
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (t[n-1]-t[i]<=mod && tav[i][0]!=sok) {
            // valahova el lehet jutni a 0. pillanaban s be lehet fejezni onnan
            mini=min(mini, tav[i][0]*(mod+r)+t[n-1]-t[i]);
        }
    }
    if (mini==sok) mini=-1;
    cout << mini << "\n";
    return 0;
}