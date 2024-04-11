#include <bits/stdc++.h>

using namespace std;
const int c=8192, k=c/2, f=3002;
vector<long long> sz[k];
int n, m, kezd[c], veg[c];
long long dp[c][f], maxi, db, sum;
void solve(int a) {
    if (a!=1) {
        int l=kezd[a+1], r=veg[a+1];
        if (a%2) l=kezd[a-1], r=veg[a-1];
        for (int i=l; i<=r; i++) {
            int si=sz[i].size()-1;
            long long ert=sz[i].back();
            for (int i=m-si; i>=0; i--) {
                dp[a][i+si]=max(dp[a][i+si], dp[a][i]+ert);
            }
        }
    }
    if (a<k) {
        for (int i=0; i<=m; i++) {
            dp[2*a][i]=dp[a][i];
            dp[2*a+1][i]=dp[a][i];
        }
        solve(2*a), solve(2*a+1);
    } else {
        int si=sz[a-k].size();
        for (int i=0; i<si; i++) {
            maxi=max(maxi, dp[a][m-i]+sz[a-k][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=0; i<k; i++) sz[i].push_back(0);
    for (int i=0; i<n; i++) {
        int x, y; cin >> x, db+=x;
        for (int j=0; j<x; j++) {
            cin >> y, sum+=y;
            if (sz[i].size()<=m) sz[i].push_back(sz[i].back()+y);
        }
    }
    for (int i=k; i<c; i++) kezd[i]=i-k, veg[i]=i-k;
    for (int i=k-1; i; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    solve(1);
    if (db<m) maxi=sum;
    cout << maxi << "\n";
    return 0;
}