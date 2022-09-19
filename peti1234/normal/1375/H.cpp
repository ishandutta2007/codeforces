#include <bits/stdc++.h>

using namespace std;
const int c=4100, s=256, c2=17;
int n, q, t[c], st[c], el[c][c2], ut[c][c2], m[c][c], db, cnt;
vector<pair<int, int> > ans;
vector<int> hol;
int add(int a, int b) {
    ans.push_back({a, b});
    return ++cnt;
}
void solve(vector<int> sz) {
    int si=sz.size();
    if (si==1) {
        m[sz[0]][sz[0]]=sz[0];
        return;
    }
    int mini=t[sz[0]], maxi=t[sz[0]], koz=0;
    for (auto x:sz) {
        mini=min(mini, t[x]);
        maxi=max(maxi, t[x]);
    }
    koz=(mini+maxi)/2;
    vector<int> bal, jobb;
    for (auto x:sz) {
        if (t[x]<=koz) {
            bal.push_back(x);
        } else {
            jobb.push_back(x);
        }
    }
    solve(bal), solve(jobb);
    vector<pair<pair<int, int>, int> > uj;
    for (int i=0; i<si; i++) {
        int l1=0, r1=0, l2=0, r2=0;
        for (int j=i; j<si; j++) {
            if (t[sz[j]]<=koz) {
                if (!l1) l1=sz[j];
                r1=sz[j];
            } else {
                if (!l2) l2=sz[j];
                r2=sz[j];
            }
            if (l1 && l2) {
                uj.push_back({{sz[i], sz[j]}, add(m[l1][r1], m[l2][r2])});
            }
        }
    }
    for (auto x:uj) {
        m[x.first.first][x.first.second]=x.second;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    db=(n+s-1)/s, cnt=n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        st[i]=(t[i]+s-1)/s;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j>=1; j--) {
            if (j<i && st[j]==st[i]) {
                break;
            }
            el[j][st[i]]=i;
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=i; j<=n; j++) {
            if (j>i && st[j]==st[i]) {
                break;
            }
            ut[j][st[i]]=i;
        }
    }

    for (int j=1; j<=db; j++) {
        vector<int> sz;
        for (int i=1; i<=n; i++) {
            if (st[i]==j) {
                sz.push_back(i);
            }
        }
        solve(sz);
    }
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        int pos=0;
        for (int i=1; i<=db; i++) {
            if (el[l][i] && ut[r][i] && el[l][i]<=ut[r][i]) {
                int ert=m[el[l][i]][ut[r][i]];
                if (pos) {
                    pos=add(pos, ert);
                } else {
                    pos=ert;
                }
            }
        }
        hol.push_back(pos);
    }
    cout << cnt << "\n";
    for (auto x:ans) {
        cout << x.first << " " << x.second << "\n";
    }
    for (auto x:hol) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}