#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c], ert[c];
long long ans;
int solve(int pos, int id) {
    int inc=0, dec=c;
    if (pos==n+1) return n+1;
    while (true) {
        if (pos==0 || pos==n+1 || t[pos]<inc && t[pos]>dec) {
            return pos-id;
        }
        if (t[pos]>inc && (t[pos]>dec || t[pos+id]>t[pos])) {
            inc=t[pos];
        } else {
            dec=t[pos];
        }
        pos+=id;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    /*for (int i=1; i<=n; i++) {

    }*/
    int pos=1;
    while (pos<=n) {
        //cout << "fontos " << pos << " " << solve(pos, 1) << "\n";
        int cel=solve(pos, 1), kov=solve(cel+1, -1);
        ert[pos]=cel;
        for (int i=pos; i<kov; i++) {
            ert[pos]=cel;
            ans+=cel-i+1;
        }
        pos=kov;
    }
    cout << ans << "\n";
    return 0;
}