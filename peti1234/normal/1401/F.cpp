#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19);
int n, q, ke[c], ve[c], xo;
long long sum[c];
long long solve(int a, int st, int fi) {
    int s=ke[a], f=ve[a];
    if (st>f || fi<s) return 0;
    if (st<=s && f<=fi) {
        int tav=f+1-s;
        return sum[a^(xo/tav)];
    }
    return solve(2*a, st, fi)+solve(2*a+1, st, fi);
}
int main()
{
    cin >> n >> q;
    n=(1<<n);
    for (int i=n; i<2*n; i++) cin >> sum[i], ke[i]=i-n, ve[i]=i-n;
    for (int i=n-1; i>=1; i--) sum[i]=sum[2*i]+sum[2*i+1], ke[i]=ke[2*i], ve[i]=ve[2*i+1];
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b;
        if (a==1) {
            cin >> c;
            b=n+xo^(b-1), sum[b]=c;
            while(b>1) {
                b/=2;
                sum[b]=sum[2*b]+sum[2*b+1];
            }
        }
        if (a==2) xo=xo^((1<<b)-1);
        if (a==3) xo=xo^(1<<b);
        if (a==4) {
            cin >> c;
            b--, c--;
            cout.flush() << solve(1, b, c) << "\n";
        }
    }
    return 0;
}