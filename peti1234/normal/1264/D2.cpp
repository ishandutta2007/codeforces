#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long n, fakt[c], kom[c][2], inv[c], ans, op, cl, ek, uk, mod=998244353;
string s;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        p/=2;
        a=a*a%mod;
    }
    return ans;
}
long long alatt(int a, int b) {
    b=max(b, 0);
    if (a<b) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    for (int i=0; i<n; i++) {
        if (s[i]==')') {
            cl++;
        }
        if (s[i]=='?') {
            uk++;
        }
    }
    for (int j=0; j<2; j++) {
        for (int i=0; i<=uk-1+j; i++) {
            kom[i][j]=alatt(uk-1+j, i);
            if (i) {
                kom[i][j]+=kom[i-1][j];
                kom[i][j]%=mod;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='(') {
            int s=min(ek+uk, uk-1-op+cl);
            if (s>=0) {
                ans+=kom[s][1];
            }
            op++;
        }
        if (s[i]=='?') {
            uk--;
            int s=min(ek+uk, uk-1-op+cl);
            if (s>=0) {
                ans+=kom[s][0];
            }
            ek++;
        }
        if (s[i]==')') {
            cl--;
        }
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}