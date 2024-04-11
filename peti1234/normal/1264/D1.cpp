#include <bits/stdc++.h>

using namespace std;
long long a[2001], b[2001], c[2001];
long long alatt[2001][2002];
long long nagy[2001][2002];
long long t[2001];
long long mod=998244353;
long long sum;
string s;
long long n;
long long ask(long long a, long long b)
{
    return alatt[a][b];
}
long long nagyask(long long a, int b)
{
    b=max(b, 0);
    return nagy[a][b];
}
long long ee(long long id, long long val)
{
    if (t[id]==-1) {
        return 0;
    }
    if (t[id]==1) {
        long long x=a[id];
        long long sx=c[id];
        long long y=b[n]-b[id];
        long long sy=c[n]-c[id];
        if (x>val) {
            return 0;
        }
        return (ask(sx, val-x)*nagyask(sy, val-y))%mod;
    }
    if (t[id]==0) {
        long long x=a[id];
        long long sx=c[id];
        x++, sx--;
        long long y=b[n]-b[id];
        long long sy=c[n]-c[id];
        if (x>val) {
            return 0;
        }
        return (ask(sx, val-x)*nagyask(sy, val-y))%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (long long i=1; i<=n; i++) {
        char x=s[i-1];
        a[i]=a[i-1], b[i]=b[i-1], c[i]=c[i-1];
        if (x=='(') a[i]++, t[i]=1;
        if (x==')') b[i]++, t[i]=-1;
        if (x=='?') c[i]++;
    }
    for (long long i=0; i<=n; i++) alatt[i][0]=1, nagy[i][0]=1;
    for (long long i=1; i<=n; i++) {
        for (long long j=1; j<=i; j++) alatt[i][j]=alatt[i-1][j]+alatt[i-1][j-1], alatt[i][j]%=mod, nagy[i][j]=alatt[i][j];
    }
    for (long long i=0; i<=n; i++) {
        for (long long j=n; j>=0; j--) {
            nagy[i][j]+=nagy[i][j+1], nagy[i][j]%=mod;
        }
    }
    for (long long k=1; k<=n; k++) {
        long long db=0;
        for (long long i=1; i<=n; i++) {
            db+=ee(i, k);
            db%=mod;
        }
        sum+=db;
        sum%=mod;
    }
    cout << sum << "\n";
    return 0;
}