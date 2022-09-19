#include <bits/stdc++.h>

using namespace std;
const int c=200000;
long long n, m, ans, ert, fakt[c+5], inv[c+5], db[c+5], fen[c+5], t[c+5], mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    db[a]+=b;
    while (a<=c) {
        fen[a]+=b;
        a+=lsb(a);
    }
}
int ask(int a) {
    int ans=0;
    while (a) {
        ans+=fen[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        add(x, 1);
    }
    ert=fakt[n];
    for (int i=1; i<=c; i++) {
        ert=ert*inv[db[i]]%mod;
    }

    for (int i=1; i<=m; i++) {
        cin >> t[i];
    }

    for (int i=1; i<=m; i++) {
        long long s=ask(t[i]-1);
        //cout << "fontos " << i << " " << s << " " << ert << "\n";
        ans=(ans+ert*s%mod*oszt(n-i+1))%mod;
        if (db[t[i]]) {
            ert=ert*oszt(n-i+1)%mod*db[t[i]]%mod;
            add(t[i], -1);
        } else {
            if (i>n) {
                ans=(ans+1)%mod;
            }
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
/*
4 4
1 2 3 4
4 3 2 1
*/