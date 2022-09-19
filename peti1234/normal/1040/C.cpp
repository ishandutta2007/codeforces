#include <bits/stdc++.h>

using namespace std;
const long long c=200002;
long long a[c], b[c], x[c], n, t, p, f=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (long long i=1; i<=n; i++) cin >> a[i];
    for (long long i=1; i<=n; i++) cin >> x[i];
    for (long long i=1; i<=n; i++) if (x[i]<i || x[i]!=x[x[i]] || x[i]<x[i-1]) p++;
    for (long long i=1; i<=n; i++) {
        if (x[i]==i) {
            if (f==i) b[i]=a[i]+t;
            else for (long long j=f; j<=i; j++) b[j]=a[i]+t-i+j+1;
            f=i+1;
        }
    }
    for (long long i=1; i<n; i++) if (i==x[i] && b[i]>=a[i+1]+t) p++;
    if (p) { cout << "No" << "\n"; return 0;}
    cout << "Yes" << "\n";
    for (long long i=1; i<=n; i++) cout << b[i] << " ";
    return 0;
}