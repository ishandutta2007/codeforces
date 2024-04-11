#include <bits/stdc++.h>
 
using namespace std;
int n, m;
long long mod=998244353;
long long gcd(long long a, long long b)
{
    if (a>b) {
        swap(a, b);
    }
    if (a==0) {
        return b;
    }
    return gcd(a, b%a);
}
long long ans(long long a, long long b)
{
    swap(a, b);
    long long c=gcd(a, b);
    a/=c, b/=c;
    long long k=mod-2;
    long long re=1;
    long long p=a;
    while(k>0) {
        if (k%2) {
            re*=p;
            re%=mod;
        }
        p*=p;
        p%=mod;
        k/=2;
    }
    re*=b;
    re%=mod;
    return re;
}
long long sum;
long long pl;
long long neg;
bool v[200001];
long long w[200001];
long long dp[2][101][51][101];
bool g[2][101][51][101];
long long solve(int a, int s, int ossz, int poz, int mi)
{
    int st=abs(s-w[a])+poz+mi;
 
    if (g[v[a]][s][st][ossz]) {
        return dp[v[a]][s][st][ossz];
    }
    g[v[a]][s][st][ossz]=true;
    if (st==m) {
        dp[v[a]][s][st][ossz]=s;
        return s;
    }
    long long bsum=sum+ossz-50;
    long long bpl=pl+poz;
    long long bmin=neg-mi;
    long long res=0;
    long long val=0;
    if (bpl>0) {
        res=ans(bpl, bsum);
        res*=solve(a, s, ossz+1, poz+1, mi);
        res%=mod;
        val+=res;
    }
    if (bmin>0) {
        res=ans(bmin, bsum);
        res*=solve(a, s, ossz-1, poz, mi+1);
        res%=mod;
        val+=res;
        val%=mod;
    }
    if (s>0) {
        res=ans(s, bsum);
        if (!v[a]) {
            res*=solve(a, s-1, ossz-1, poz, mi);
        } else {
            res*=solve(a, s+1, ossz+1, poz, mi);
        }
        res%=mod;
        val+=res;
        val%=mod;
    }
    dp[v[a]][s][st][ossz]=val;
    return val;
 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> w[i];
        if (v[i]) {
            pl+=w[i];
        } else {
            neg+=w[i];
        }
        sum+=w[i];
    }
    for (int i=1; i<=n; i++) {
        int k=pl;
        if (v[i]) {
            pl-=w[i];
        } else {
            neg-=w[i];
        }
        cout << solve(i, w[i], 50, 0, 0) << "\n";
        if (v[i]) {
            pl+=w[i];
        } else {
            neg+=w[i];
        }
    }
    return 0;
}