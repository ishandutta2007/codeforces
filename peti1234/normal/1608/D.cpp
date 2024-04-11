#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, fakt[c], inv[c], ans, po[c],  mod=998244353;
long long xx, xb, xw, bx, wx, bb, ww, bw, wb, sb, sw;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(int a, int b) {
    if (a<0 || a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fakt[0]=1, inv[0]=1, po[0]=1;
    for (int i=1; i<=2*n; i++) po[i]=2*po[i-1]%mod;
    for (int i=1; i<=2*n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=1; i<=n; i++) {
        char a, b;
        cin >> a >> b;
        if (a=='B') sb++; if (b=='B') sb++;
        if (a=='W') sw++; if (b=='W') sw++;
        if (a=='?' && b=='?') xx++;
        if (a=='B' && b=='?') bx++;
        if (a=='W' && b=='?') wx++;
        if (a=='?' && b=='B') xb++;
        if (a=='?' && b=='W') xw++;
        if (a=='B' && b=='B') bb++;
        if (a=='B' && b=='W') bw++;
        if (a=='W' && b=='B') wb++;
        if (a=='W' && b=='W') ww++;
    }
    //cout << "... " << sb << " " << sw << "\n";
    //cout << "kezd " << 2*n-sb-sw << " " << n-sb << "\n";
    ans=alatt(2*n-sb-sw, n-sb);
    if (!bb && !ww) {
        ans=(ans+mod-alatt(2*n-2*xx-sb-sw, n-sb-xx)*po[xx]%mod)%mod;
        //cout << "valt " << ans << "\n";
        if (!wb && !wx && !xb) ans++;
        if (!bw && !bx && !xw) ans++;
    }
    cout << ans%mod << "\n";
    return 0;
}