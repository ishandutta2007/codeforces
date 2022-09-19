#include <bits/stdc++.h>

using namespace std;
long long w, n, a, b, c, l, r, db, ans;
bool jo[40001];
long long e[40001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> n, c=a*b, db=0;
        for (long long i=0; i<c; i++) jo[i]=0, e[i]=0;
        for (long long i=0; i<c; i++) if (i%a%b!=i%b%a) jo[i]=true, db++;
        for (long long i=1; i<c; i++) e[i]=e[i-1]+jo[i];
        for (long long i=1; i<=n; i++) {
            cin >> l >> r, ans=0, l--;
            long long x=l%c, y=r%c;
            l-=x, r-=y;
            ans=e[y]-e[x];
            ans+=db*((r-l)/c);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}