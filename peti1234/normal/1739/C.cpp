#include <bits/stdc++.h>

using namespace std;


/*
c meg mod erteket be kell allitani
calc n utan n-ig tud faktorialis, inverz es a alatt b-t szamolni
*/


const int c=500005;
long long mod=998244353;



long long fakt[c], inv[c];
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
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

long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
long long alatt2(long long a, long long b) {
    if (a<b || b<0) return 0;
    long long ans=1;
    for (int i=1; i<=b; i++) {
        ans=ans*(a+1-i)%mod;
    }
    return ans*inv[b]%mod;
}
void calc(int a) {
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=a; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
}

long long t[c], n;

void solve() {
    cin >> n;
    long long a=0, b=0;
    for (int i=1; i<=n/2; i++) {
        long long x=alatt(n-2*i, n/2-i), y=alatt(n-2*i, n/2-i-1);
        a+=y, b+=y;
        if (i%2) a+=x;
        else b+=x;
    }
    cout << a%mod << " " << b%mod << " " << 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    calc(200005);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
4
*/