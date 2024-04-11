#include <bits/stdc++.h>

using namespace std;
const int c=1005, k=62;
long long n, l, r, z, alatt[c][c], dp[k][2*c], po[k], cnt[k], mod=1e9+7;
int lepes;
unordered_map<long long, int> m[k];
long long solve(int id, long long ert) {
    if (ert==0) {
        return (po[id]>z ? 1 : 0);
    }
    if (m[id].find(ert)!=m[id].end()) {
        return dp[id][m[id][ert]];
    }
    lepes++;
    m[id][ert]=++cnt[id];
    long long ans=0;
    int kezd=((z & po[id]) ? 1 : 0);
    for (int i=kezd; i<=min(n, ert); i+=2) {
        ans=(ans+alatt[n][i]*solve(id+1, (ert-i)/2))%mod;
        //solve(id+1, (ert-i)/2);
    }
    //cout << "solve " << id << " " << ert << " " << ans << "\n";
    dp[id][cnt[id]]=ans;
    return ans;
}
int main()
{
    cin >> n >> l >> r >> z;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            alatt[i][j]=(j==0 ? 1 : (alatt[i-1][j]+alatt[i-1][j-1])%mod);
        }
    }
    po[0]=1;
    for (int i=1; i<k; i++) {
        po[i]=2*po[i-1];
    }
    cout << (solve(0, r)-solve(0, l-1)+mod)%mod << "\n";
    /*for (int i=1; i<k; i++) {
        cout << cnt[i] << "\n";
    }*/
    //cout << lepes << "\n";
    return 0;
}

/*
1000 123456789 123456789987654321 564263563252
*/