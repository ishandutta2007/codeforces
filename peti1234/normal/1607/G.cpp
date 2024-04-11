#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, m, a[c], b[c], x[c], y[c], sa, sb, o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> a[i] >> b[i];
            x[i]=max(o, a[i]-m), y[i]=max(o, b[i]-m);
            sa+=x[i], sb+=y[i];
        }
        for (int i=1; i<=n; i++) {
            long long dif=a[i]+b[i]-x[i]-y[i]-m, k=min(dif, abs(sa-sb));
            if (sa<sb) x[i]+=k, sa+=k;
            else y[i]+=k, sb+=k;
            dif-=k;
            x[i]+=(dif+1)/2, sa+=(dif+1)/2;
            y[i]+=dif/2, sb+=dif/2;
        }
        cout << abs(sa-sb) << "\n";
        for (int i=1; i<=n; i++) {
            cout << a[i]-x[i] << " " << b[i]-y[i] << "\n";
        }

        sa=0, sb=0;
        for (int i=1; i<=n; i++) a[i]=b[i]=x[i]=y[i]=0;
    }
    return 0;
}