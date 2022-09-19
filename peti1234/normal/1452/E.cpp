#include <bits/stdc++.h>

using namespace std;
const int c=4002;
int n, m, k, ans, alap, cnt, valt, maxi, l[c], r[c], t[c];
void add(int a, int b) {
    t[a]+=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
        l[i]+=k, r[i]+=k;
    }
    for (int i=1; i<=m+k; i++) {
        int kezd=i, veg=i+k-1;
        for (int j=1; j<=m+k; j++) t[j]=0;
        alap=0, cnt=0, valt=0, maxi=0;
        for (int j=1; j<=n; j++) {
            int is=max(0, 1+min(r[j], veg)-max(l[j], kezd)), hossz=r[j]-l[j]+1;
            alap+=is;
            add(l[j]+is-k+1, 1);
            add(min(l[j], r[j]-k+1)+1, -1);
            add(max(l[j], r[j]-k+1)+1, -1);
            add(r[j]-is+2, 1);
        }
        for (int i=1; i<=m+k; i++) {
            valt+=t[i];
            cnt+=valt;
            maxi=max(maxi, cnt);
        }
        ans=max(ans, alap+maxi);
    }
    cout << ans << endl;
    return 0;
}