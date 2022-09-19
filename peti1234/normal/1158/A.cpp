#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long a[100001];
long long b[100001];
long long ans;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=1; i<=n; i++) {
        cin >> a[i];
        sum+=a[i];
        a[i]*=-1;
    }
    for (long long j=1; j<=m; j++) {
        cin >> b[j];
    }
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for (long long i=1; i<=n; i++) {
        a[i]*=-1;
    }
    if (a[1]>b[1]) {
        cout << -1 << endl;
        return 0;
    }
    ans=sum*m;
    long long db=-1;
    for (long long i=1; i<=m; i++) {
        if (b[i]!=a[1]) {
            db++;
            ans+=b[i];
            ans-=a[db/(m-1)+1];
        }
    }
    cout << ans << endl;
    return 0;
}