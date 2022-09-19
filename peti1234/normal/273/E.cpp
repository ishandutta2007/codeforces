#include<bits/stdc++.h>

using namespace std;
const int c=200002;
long long mod=1000000007, db[4], dp[1002][4], ans;
int n, p, t[c], ert[c], pos, l, r, lmax, rmax;
int mex(int a, int b) {
    if (a>b) {
        swap(a, b);
    }
    if (a) {
        return 0;
    }
    if (b!=1) {
        return 1;
    }
    return 2;
}
long long sum(int a, int b) {
    long long tav=b-a+1, s=tav*(tav-1)/2;
    return tav*(p-a)-s;
}
int main()
{
    cin >> n >> p;
    if (p==1) {
        cout << 0 << "\n";
        return 0;
    }
    l=1, r=1;
    ert[1]=2, pos=1;
    while (ert[pos]<p) {
        lmax=3*ert[l]+2;
        rmax=ert[r]/2*3+ert[r]%2;
        pos++;
        t[pos]=mex(t[l], t[r]);
        if (t[pos]==t[pos-1]) {
            pos--;
        }
        ert[pos]=min({lmax, rmax, p});
        if (lmax<=rmax) {
            l++;
        }
        if (rmax<=lmax) {
            r++;
        }
    }
    for (int i=1; i<=pos; i++) {
        //cout << i << " " << t[i] << " " << ert[i] << "\n";
        db[t[i]]+=sum(ert[i-1]+1, ert[i]);
        db[t[i]]%=mod;
    }
    dp[0][0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<3; k++) {
                dp[i][j^k]+=dp[i-1][j]*db[k];
                dp[i][j^k]%=mod;
            }
        }
    }
    for (int i=1; i<=3; i++) {
        ans+=dp[n][i];
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}