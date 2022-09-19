#include <bits/stdc++.h>

using namespace std;
long long n, p, db, sum, maxi, t[400002], x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i=1; i<=n; i++) cin >> t[i], t[i+n]=t[i];
    for (int i=1; i<=2*n; i++) {
        sum+=t[i]*(t[i]+1)/2, db+=t[i];
        while(db>=p) x++, sum-=t[x]*(t[x]+1)/2, db-=t[x];
        if (x) maxi=max(maxi, sum+t[x]*(p-db)-(p-db)*(p-db-1)/2);
    }
    cout << maxi << "\n";
    return 0;
}