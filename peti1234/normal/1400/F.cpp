#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20), k=22;
int h, n, n2, lep[c][10], regi[c], uj[c], ans=c;
string s;
vector<int> sz;
int main()
{
    cin >> s >> n;
    n2=(1<<n);
    h=s.size();
    for (int i=0; i<n2; i++) {
        bool baj=0;
        for (int j=0; j<n; j++) {
            if (n%(j+1)==0 && (i & (1<<j))) {
                baj=1;
            }
        }
        if (!baj) {
            sz.push_back(i);
            for (int j=1; j<=9; j++) {
                int kov=i*(1<<j)+(1<<(j-1));
                kov%=n2;
                //cout << "kezd " << kov << "\n";
                bool spec=0;
                for (int ii=0; ii<n; ii++) {
                    if ((kov & (1<<ii)) && n%(ii+1)==0 && n!=ii+1) {
                        spec=1;
                    }
                    if ((kov & (1<<ii)) && spec) {
                        kov-=(1<<ii);
                    }
                }
                //cout << "vege " << kov << "\n";
                lep[i][j]=kov;
            }
        }
    }
    for (auto x:sz) {
        uj[x]=c;
    }
    for (auto k:s) {
        int ert=(k-'0');
        for (auto x:sz) {
            uj[x]=min(uj[x], regi[x]+1);
            uj[lep[x][ert]]=min(uj[lep[x][ert]], regi[x]);
        }
        for (auto x:sz) {
            regi[x]=uj[x], uj[x]=c;
        }
    }
    for (auto x:sz) {
        ans=min(ans, regi[x]);
    }
    cout << ans << "\n";
    return 0;
}
/*
1
*/