#include <bits/stdc++.h>

using namespace std;
const int c=40002;
long long a[c], b[c], n, m, k, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    for (int i=1; i<=n; i++) {
        if (k%i==0) {
            long long p=0, q=0, x=i, y=k/x, cnt=0;
            for (int i=1; i<=n; i++) {
                if (a[i]==1) {
                    cnt++;
                    if (cnt>=x) p++;
                } else cnt=0;
            }
            cnt=0;
            for (int i=1; i<=m; i++) {
                if (b[i]==1) {
                    cnt++;
                    if (cnt>=y) q++;
                } else cnt=0;
            }
            //cout << x << " " << y << " " << p << " " << q << endl;
            sum+=p*q;
        }
    }
    cout << sum << "\n";
    return 0;
}