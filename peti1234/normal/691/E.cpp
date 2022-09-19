#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long n, k, pos=70, ert[c], t[c][c][200], mod=1e9+7, po=1;
void mul(int a, int b, int c) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                t[i][k][c]=(t[i][k][c]+t[i][j][a]*t[j][k][b])%mod;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    k--;
    for (int i=1; i<=n; i++) {
        cin >> ert[i];
    }
    for (int i=1; i<=n; i++) {
        t[i][i][pos]=1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            long long db=__builtin_popcountll(ert[i]^ert[j]);
            if (db%3==0) {
                t[i][j][0]=1;
            }
            //cout << db << "\n";
        }
    }
    for (int i=0; i<64; i++) {
        if (k & po) {
            mul(pos, i, pos+1);
            pos++;
        }
        po*=2;
        mul(i, i, i+1);
    }
    long long sum=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            sum=(sum+t[i][j][pos])%mod;
        }
    }
    cout << sum << "\n";
    return 0;
}