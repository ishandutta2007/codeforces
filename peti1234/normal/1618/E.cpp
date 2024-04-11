#include <bits/stdc++.h>

using namespace std;
const int c=50005;
long long w, n, sum, sn, t[c], ans[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        bool baj=0;
        sn=sum/(n*(n+1)/2);
        if ((sn*n*(n+1))!=2*sum) {
            baj=1;
        }
        for (int i=1; i<=n; i++) {
            int el=(i==1 ? n : i-1);
            long long dif=t[el]+sn-t[i];
            if (dif%n || dif<=0) {
                baj=1;
            }
            ans[i]=dif/n;
        }

        if (baj) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

        sum=0, sn=0;

    }
    return 0;
}
/*
1
3
12 16 14
*/