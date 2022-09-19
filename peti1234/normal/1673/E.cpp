#include <bits/stdc++.h>

using namespace std;
const int c=(1<<20);
long long n, k, pref[c], t[c], dp[25][3], ans[c], o=0;
void calc(int ert, int kezd, int veg) {
    int a=veg-kezd+(kezd>1)+(n>veg), b=(kezd>1)+(n>veg);
    //cout << "calc " << ert << " " << kezd << " " << veg << " " << a << " " << b << "\n";
    //cout << "dp " << dp[a][b] << "\n";
    if (dp[a][b]) {
        ans[ert]=1-ans[ert];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        pref[i]=pref[i-1]+__builtin_ctz(i);
    }
    cin >> n >> k;
    for (int i=0; i<25; i++) {
        for (int j=0; j<3; j++) {
            int a=n-1-i, b=max(o, k-j);
            if (a<0) continue;
            for (int s=b; s<=a; s++) {
                if (pref[a]==pref[s]+pref[a-s]) {
                    dp[i][j]=1-dp[i][j];
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        long long ert=t[i];
        calc(ert, i, i);
        for (int j=i+1; j<=n; j++) {
            if (t[j]<20) {
                long long s=(1<<t[j]);
                ert*=s;
            } else ert=c;
            if (ert<c) calc(ert, i, j);
            else break;
        }
    }
    bool f=0;
    for (int i=c-1; i>=0; i--) {
        if (ans[i]) f=1;
        if (f) cout << ans[i];
    }
    if (!f) {
        cout << 0;
    }
    cout << "\n";
    return 0;
}
/*
2 1
1 1
*/