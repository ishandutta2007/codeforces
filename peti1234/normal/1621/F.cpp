#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        long long n, aa, bb, cc, ans=0;
        cin >> n >> aa >> bb >> cc;
        int ee=0, ebl=0, oo=0, obl=0, cnt=0, kdb=0;
        vector<int> sz;
        string s;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (i==0) {
                if (s[i]=='0') obl++;
                else ebl++;
            } else {
                if (s[i]==s[i-1]) {
                    if (s[i]=='0') oo++, cnt++;
                    else ee++;
                } else {
                    if (s[i]=='0') cnt=1, obl++;
                    else {
                        if (ebl) sz.push_back(cnt);
                        cnt=0;
                        ebl++;
                    }
                }
            }
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<=obl; i++) {
            if (0<i && i<ebl) {
                kdb+=sz[i-1];
            }
            int odb=oo+i, edb=ee+max(0, min(ebl-1, i));
            odb=min(odb, edb+1), edb=min(edb, odb+1);
            if (edb+1>=kdb && (odb>kdb || edb+1>kdb)) {
                ans=max(ans, edb*bb+(odb-i)*aa-i*cc);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}