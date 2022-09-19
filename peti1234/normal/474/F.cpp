#include <bits/stdc++.h>

using namespace std;
const int c=262144, k=c/2;
int n, m, kezd[c], veg[c], mini[c], mindb[c], lnko[c], s[c][3];
void solve(int a, int l, int r) {
    s[a][2]=0;
    if (kezd[a]>r || veg[a]<l) {
        s[a][0]=0, s[a][1]=1e9, s[a][2]=0;
        return;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        s[a][0]=lnko[a], s[a][1]=mini[a], s[a][2]=mindb[a];
        return;
    }
    int x=2*a, y=2*a+1;
    solve(x, l, r), solve(y, l, r);
    s[a][0]=__gcd(s[x][0], s[y][0]);
    s[a][1]=min(s[x][1], s[y][1]);
    if (s[a][1]==s[x][1]) s[a][2]+=s[x][2];
    if (s[a][1]==s[y][1]) s[a][2]+=s[y][2];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=k; i<k+n; i++) {
        cin >> lnko[i];
    }
    for (int i=k; i<c; i++) {
        kezd[i]=i-k+1, veg[i]=i-k+1, mini[i]=lnko[i], mindb[i]=1;
    }
    for (int i=k-1; i>=1; i--) {
        int a=2*i, b=2*i+1;
        kezd[i]=kezd[a], veg[i]=veg[b], lnko[i]=__gcd(lnko[a], lnko[b]);
        mini[i]=min(mini[a], mini[b]);
        if (mini[i]==mini[a]) mindb[i]+=mindb[a];
        if (mini[i]==mini[b]) mindb[i]+=mindb[b];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int l, r; cin >> l >> r;
        solve(1, l, r);
        if (s[1][0]!=s[1][1]) s[1][2]=0;
        cout << r-l+1-s[1][2] << "\n";
    }
    return 0;
}