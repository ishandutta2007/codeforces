#include <bits/stdc++.h>

using namespace std;
const int c=1000002, p=20;
int n, m, perm[c][p], l[c], r[c];
bool kezd[p], veg[p];
string s;
int k, dist[1<<p], ki[1<<p], kert[c], vert[c];
int ans=c, xx, yy;
void dfs(int pos, int id, int tav) {
    dist[pos]=tav, ki[pos]=id;
    for (int i=0; i<k; i++) {
        int uj=(pos^(1<<i));
        if (dist[uj]>tav+1) {
            dfs(uj, id, tav+1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> s;
    for (int i=0; i<k; i++) {
        kezd[i]=(s[i]-'0'==1);
    }
    cin >> s;
    for (int i=0; i<k; i++) {
        veg[i]=(s[i]-'0'==1);
    }
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    for (int i=0; i<k; i++) {
        perm[n+1][i]=i;
        if (veg[i]) {
            vert[n+1]+=(1<<i);
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=0; j<k; j++) {
            perm[i][j]=perm[i+1][j];
        }
        swap(perm[i][l[i]], perm[i][r[i]]);
        for (int j=0; j<k; j++) {
            if (kezd[j]) {
                kert[i]+=(1<<perm[i][j]);
            }
            if (veg[j]) {
                vert[i]+=(1<<perm[i][j]);
            }
        }
    }
    for (int i=0; i<(1<<k); i++) {
        dist[i]=k+1;
    }
    for (int i=n-m+1; i>=1; i--) {
        dfs(vert[i+m], i+m, 0);
        if (ans>dist[kert[i]]) {
            ans=dist[kert[i]];
            xx=i, yy=ki[kert[i]]-1;
        }
    }
    cout << k-ans << "\n" << xx << " " << yy << "\n";
    return 0;
}