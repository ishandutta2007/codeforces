#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long n, m, r, k;
long long sor[c], oszlop[c], komdb[c], komsum[c];
long long lo, hi, mid, db, sum;
void calc(long long ert) {
    db=sum=0;
    for (int i=1; i<=n; i++) {
        long long s=(ert-1)/i;
        if (s<m) {
            db+=sor[i]*(komdb[m]-komdb[s]);
            sum+=sor[i]*i*(komsum[m]-komsum[s]);
        }
    }
}
int main()
{
    cin >> n >> m >> r >> k;
    for (long long i=1; i<=n; i++) {
        int ert=min({i, n-i+1, n-r+1, r});
        sor[ert]++;
    }
    for (long long i=1; i<=m; i++) {
        int ert=min({i, m-i+1, m-r+1, r});
        oszlop[ert]++;
    }
    for (int i=1; i<=m; i++) {
        komdb[i]=komdb[i-1]+oszlop[i];
        komsum[i]=komsum[i-1]+oszlop[i]*i;
    }
    lo=0, hi=n*m;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        calc(mid);
        if (db>=k) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    calc(hi);
    sum+=(k-db)*lo;
    long double ans=sum;
    ans/=(n-r+1)*(m-r+1);
    cout.precision(15);
    cout << ans << "\n";
    return 0;
}