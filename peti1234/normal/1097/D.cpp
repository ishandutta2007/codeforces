#include <bits/stdc++.h>

using namespace std;
const int c=62;
long long n, k, regi[c][c], uj[c][c], oo[100], ans=1, mod=1e9+7;
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
void calc(int st) {
    if (regi[st][st]) {
        return;
    }
    regi[st][st]=1;
    for (int i=1; i<=k; i++) {
        for (int a=0; a<=st; a++) {
            for (int b=0; b<=a; b++) {
                uj[st][b]=(uj[st][b]+regi[st][a]*oo[a+1])%mod;
            }
        }
        for (int a=0; a<=st; a++) {
            regi[st][a]=uj[st][a];
            uj[st][a]=0;
        }
    }
}
int main()
{
    for (int i=0; i<100; i++) {
        oo[i]=oszt(i);
    }
    cin >> n >> k;
    for (long long i=2; i*i<=n; i++) {
        if (n%i) {
            continue;
        }
        int cnt=0;
        long long po[c];
        po[0]=1;
        while (n%i==0) {
            cnt++;
            po[cnt]=po[cnt-1]*i;
            n/=i;
        }
        calc(cnt);
        long long sum=0;
        for (int i=0; i<=cnt; i++) {
            sum=(sum+po[i]%mod*regi[cnt][i])%mod;
        }
        ans=ans*sum%mod;
    }
    if (n>1) {
        calc(1);
        long long sum=(regi[1][0]+(n%mod*regi[1][1]))%mod;
        ans=ans*sum%mod;
    }
    cout << ans << "\n";
    return 0;
}