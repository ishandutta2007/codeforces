#include <bits/stdc++.h>

using namespace std;
const int c=300005, k=20;
int q, kov[c], fel[c][k];
long long db[c], ar[c];
long long kell, van, sum;
void solve(int a) {
    long long mini=min(kell-van, db[a]);
    van+=mini, sum+=mini*ar[a];
    db[a]-=mini;
    if (a!=0) {
        solve(kov[a]);
    }
    while (kov[a]!=0 && db[kov[a]]==0) {
        kov[a]=kov[kov[a]];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    cin >> db[0] >> ar[0];
    for (int i=1; i<=q; i++) {
        int s;
        cin >> s;
        if (s==1) {
            cin >> kov[i] >> db[i] >> ar[i];
            fel[i][0]=kov[i];
            for (int j=1; j<k; j++) {
                fel[i][j]=fel[fel[i][j-1]][j-1];
            }
        }
        if (s==2) {
            int kezd;
            cin >> kezd >> kell;
            van=0, sum=0;
            while (van<kell && db[kezd]) {
                int pos=kezd;
                for (int i=k-1; i>=0; i--) {
                    if (db[fel[pos][i]]) {
                        pos=fel[pos][i];
                    }
                }
                long long mini=min(kell-van, db[pos]);
                van+=mini, sum+=mini*ar[pos];
                db[pos]-=mini;
            }
            //cout << "valasz: ";
            cout << van << " " << sum << "\n";
        }
    }
    return 0;
}