#include <bits/stdc++.h>

using namespace std;
const int c=22005;
long long w, n, a[c], b[c], sum, ans, alap;
bool regi[c], uj[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            sum+=a[i];
            alap+=a[i]*a[i]*(n-2);
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
            sum+=b[i];
            alap+=b[i]*b[i]*(n-2);
        }
        for (int i=0; i<=sum; i++) {
            regi[i]=0, uj[i]=0;
        }
        regi[0]=1;

        for (long long i=1; i<=n; i++) {
            for (int j=0; j<=sum; j++) {
                if (regi[j]) {
                    uj[j+a[i]]=1;
                    uj[j+b[i]]=1;
                }
            }
            for (int j=0; j<=sum; j++) {
                regi[j]=uj[j];
                uj[j]=0;
            }
        }
        ans=1e18;
        for (long long i=0; i<=sum; i++) {
            if (regi[i]) {
                ans=min(ans, alap+i*i+(sum-i)*(sum-i));
            }
        }

        cout << ans << "\n";

        ans=0, alap=0, sum=0;
    }
    return 0;
}