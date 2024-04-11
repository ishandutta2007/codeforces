#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, sum, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        sum+=y;
        t[i]=x-y;
    }
    sort(t+1, t+n+1);
    reverse(t+1, t+n+1);
    pref[0]=sum;
    for (int i=1; i<=n; i++) {
        pref[i]=pref[i-1]+t[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (n%__gcd(a, b)) {
            cout << -1 << "\n";
            continue;
        }
        long long ans=-1;
        if (a>=500) {
            for (int i=0; i*a<=n; i++) {
                if ((n-i*a)%b==0) {
                    ans=max(ans, pref[i*a]);
                }
            }
        } else {
            int pos=n;
            while (pos>0 && pos%a) {
                pos-=b;
            }
            if (pos>=0) {
                ans=pref[pos];
                long long lep=a*b/__gcd(a, b);
                for (int p=20; p>=0; p--) {
                    long long x=(pos-lep*(1<<p)), y=x+lep;
                    if (0<=x && pref[x]>pref[y]) {
                        ans=pref[x];
                        pos=x;
                    }
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}