#include <bits/stdc++.h>

using namespace std;
const int c=2005;
long long n, m, t[c][c], ans;
long long mp(int o, int x, int y) {
    // az o oszlopban mikor lesz eloszor jobb az y-nal levo oszlop
    // y>x
    long long tav=y-x;
    long long ert=t[x][o]*t[x][o]-t[y][o]*t[y][o]+tav*tav;
    if (ert>=0) {
        return y-ert/(2*tav);
    }
    return y+(-ert+2*tav-1)/(2*tav);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n++, m++;
    for (int i=1; i<=n; i++) {
        vector<int> sz;
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='1') {
                sz.push_back(j);
            }
        }
        int pos=0;
        for (int j=1; j<=m; j++) {
            t[i][j]=2*c;
            if (sz.size()>0) {
                if (pos+1<sz.size() && abs(j-sz[pos])>=abs(j-sz[pos+1])) {
                    pos++;
                }
                t[i][j]=abs(j-sz[pos]);
            }
        }
    }
    for (int j=1; j<=m; j++) {
        vector<int> sz;
        int si=0;
        for (int i=1; i<=n; i++) {
            while (si>=2 && mp(j, sz[si-1], i)<=mp(j, sz[si-2], sz[si-1]) || si>=1 && mp(j, sz[si-1], i)<=1) {
                sz.pop_back();
                si--;
            }

            if (si==0 || mp(j, sz[si-1], i)<=n) sz.push_back(i), si++;
        }
        int cel=n+1;
        for (int x=si-1; x>=0; x--) {
            int s=(x==0 ? 1 : mp(j, sz[x-1], sz[x]));
            for (int i=s; i<cel; i++) {
                ans+=t[sz[x]][j]*t[sz[x]][j]+(i-sz[x])*(i-sz[x]);
            }
            cel=s;
        }
    }
    cout << ans << "\n";
    return 0;
}