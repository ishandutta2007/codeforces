#include <bits/stdc++.h>

using namespace std;
int n, m, len, pref[200005];
vector<int> pos[9];
string s;
void solve() {
    cin >> s;
    n=s.size();
    cin >> len >> m;
    for (int i=1; i<=n; i++) {
        pref[i]=(pref[i-1]+s[i-1]-'0');
        if (i>=len) {
            int ert=(pref[i]-pref[i-len])%9;
            pos[ert].push_back(i-len+1);
        }
    }
    while (m--) {
        int l, r, k, ert, x=n+1, y=n+1;
        cin >> l >> r >> k;
        ert=(pref[r]-pref[l-1])%9;
        for (int i=0; i<9; i++) {
            int s=(k-i*ert+90)%9;
            if (i==s && pos[i].size()>1 && pos[i][0]<x) {
                x=pos[i][0], y=pos[i][1];
            }
            if (i!=s && pos[i].size()>0 && pos[s].size()>0 && pos[i][0]<x) {
                x=pos[i][0], y=pos[s][0];
            }
        }
        if (x==n+1) {
            x=-1, y=-1;
        }
        //cout << "valasz.............. ";
        cout << x << " " << y << "\n";
    }



    for (int i=0; i<9; i++) pos[i].clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
1003004
4 1
1 2 1
*/