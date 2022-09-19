#include <bits/stdc++.h>

using namespace std;
const int c=100002;
long long ans=1, n, sum, kis, nagy, t[c], mod=1e9+7;
map<int, int> m;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        m[t[i]]++;
        ans*=oszt(m[t[i]]);
        ans%=mod;
        sum+=t[i];
    }
    if (sum%n) {
        cout << 0 << "\n";
        return 0;
    }
    sum/=n;
    for (int i=1; i<=n; i++) {
        if (t[i]<sum) {
            kis++;
        }
        if (t[i]>sum) {
            nagy++;
        }
    }
    if (min(kis, nagy)<=1) {
        for (int i=1; i<=n; i++) {
            ans*=i;
            ans%=mod;
        }
        cout << ans << "\n";
        return 0;
    }
    for (int i=kis+nagy+1; i<=n; i++) {
        ans*=i;
        ans%=mod;
    }
    ans*=2, ans%=mod;
    for (int i=1; i<=kis; i++) {
        ans*=i;
        ans%=mod;
    }
    for (int i=1; i<=nagy; i++) {
        ans*=i;
        ans%=mod;
    }
    cout << ans << "\n";
    return 0;
}