#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int t[c], el[c], ut[c], mini[c], maxi[c], pos, pp, cnt, ert, n;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        ert=max(ert, t[i]);
        if (t[i]) {
            if (!el[t[i]]) {
                el[t[i]]=i;
            }
            ut[t[i]]=i;
        }
    }
    for (pos=1; ; pos++) {
        mini[pos]=mini[pos-1]+2;
        maxi[pos]=maxi[pos-1]+5;
        if (el[pos]) {
            mini[pos]=max(mini[pos], ut[pos]);
            maxi[pos]=min(maxi[pos], el[pos]+4);
        }
        if (mini[pos]>maxi[pos]) {
            baj=1;
        }
        if (mini[pos]>n) {
            pos--;
            break;
        }
    }
    pp=pos;
    for (int i=n; i>=1; i--) {
        if (cnt>=2 && (!el[pos] || el[pos]>i) && maxi[pos-1]>=i) {
            pos--, cnt=0;
        }
        t[i]=pos, cnt++;
    }
    if (pp<ert || maxi[pp]<n || cnt<2) {
        baj=1;
    }
    if (baj) {
        cout << -1 << "\n";
        return 0;
    }
    cout << pp << "\n";
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}