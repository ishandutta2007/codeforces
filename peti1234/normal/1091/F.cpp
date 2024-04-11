#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, t[c], f[c], sum, ert, rert, upos, szf, viz, lava, lk;
bool vviz;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    cin >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='G') f[i+1]=1;
        if (s[i]=='W') f[i+1]=2;
    }
    for (int i=1; i<=n; i++) {
        if (f[i]==2) vviz=1;
        if (f[i]==0) lava+=t[i];
        if (f[i]==1) szf+=t[i];
        if (f[i]==2) viz+=t[i];
        if (f[i]) ert+=t[i];
        else ert-=t[i];
        if (ert<=0) {
            sum+=lava+3*viz+5*szf;
            if (!vviz) sum-=5*ert;
            else sum-=3*ert;
            upos=i, szf=0, viz=0, lava=0, ert=0;
        }
    }
    sum+=lava+3*viz+5*szf;
    rert=ert, lk=ert;
    for (int i=n; i>upos; i--) {
        if (f[i]==1) {
            long long mini=min({lk, 2*t[i]});
            ert-=mini, sum-=2*mini;
            lk-=mini;
        }
        if (f[i]) rert-=t[i];
        else rert+=t[i];
        lk=min(lk, rert);
    }
    sum-=ert;
    cout << sum << "\n";
    return 0;
}