#include <bits/stdc++.h>

using namespace std;
const int c=100002, s=100000;
long long n, m, ans[c], db[c];
bool v[c];
long long valt(long long x) {
    return x/s+((x%s)!=0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    v[0]=1;
    for (int i=1; i<=n; i++) {
        int q;
        long long a, b;
        cin >> q >> a >> b;
        for (int j=0; j<=m; j++) {
            if (ans[j]!=i) {
                db[j]=0;
            }
            if (v[j] && db[j]<b) {
                long long kov=0;
                if (q==1) {
                    kov=j+valt(a);
                }
                if (q==2) {
                    kov=valt(a*j);
                }
                if (kov<=m && !v[kov]) {
                    v[kov]=1;
                    ans[kov]=i;
                    db[kov]=db[j]+1;
                }
            }
        }
    }
    for (int i=1; i<=m; i++) {
        if (!v[i]) {
            ans[i]=-1;
        }
        cout << ans[i] << " ";
    }
    return 0;
}