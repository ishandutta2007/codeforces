#include <bits/stdc++.h>

using namespace std;
long long n, q;
string s;
long long t[100001];
long long p[100001];
long long mod=1000000007;
long long ans(long long e, long long o)
{
    cout << (p[e]-1)*(p[o])%mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        t[i+1]=s[i]-'0'+t[i];
        //cout << t[i+1];
    }
    p[0]=1;
    for (int i=1; i<=n; i++) {
        p[i]=p[i-1]*2;
        p[i]%=mod;
    }
    for (int i=1; i<=q; i++) {
        long long l, r;
        cin >> l >> r;
        long long a=t[r]-t[l-1];
        ans(a, r-l+1-a);
    }
    return 0;
}