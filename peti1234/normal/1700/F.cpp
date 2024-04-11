#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, ans, si[2];
bool t[c][4];
vector<int> v[2];
void add(int i, int j) {
    if (t[i][j]==t[i][j+2]) return;
        //cout << "fontos " << i << " " << j << "\n";
    int ert=t[i][j];
    if (!ert) ert=-1;
    if (ert*si[j]<0) {
        ans+=i-v[j].back();
        v[j].pop_back();
        si[j]+=ert;
    } else if (ert*si[1-j]<0) {
        ans+=i-v[1-j].back()+1;
        v[1-j].pop_back();
        si[1-j]+=ert;
    } else {
        v[j].push_back(i);
        si[j]+=ert;
    }
}
void solve() {
    cin >> n;
    for (int j=0; j<4; j++) {
        for (int i=1; i<=n; i++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        if (si[0]) {
            add(i, 0);
            add(i, 1);
        } else {
            add(i, 1);
            add(i, 0);
        }
        for (int j=0; j<2; j++) {

        }
    }
    //cout << "vege " << si[0] << " " << si[1] << "\n";
    if (si[0] || si[1]) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}
int main()
{
    solve();
    return 0;
}
/*
5
0 1 0 1 0
1 1 0 0 1
1 0 1 0 1
0 0 1 1 0
*/