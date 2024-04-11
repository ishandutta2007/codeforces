#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long mod=998244353, ans=1;
int n, k, p[c], inv[c];
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        p[i]=n-p[i];
        inv[p[i]]=i;
    }
    for (int i=1; i<n; i++) {
        int a=p[i], b=p[i+1];
        if (inv[a-1]>inv[b-1]) {
            k--;
        }
    }
    for (int i=1; i<k; i++) {
        ans*=n+k-i, ans%=mod;
        ans*=oszt(i), ans%=mod;
    }
    cout << (k>0 ? ans : 0) << "\n";
    return 0;
}