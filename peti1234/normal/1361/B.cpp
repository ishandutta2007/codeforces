#include <bits/stdc++.h>

using namespace std;
const long long mod=1000000007, c=1000002;
long long w, n, p, cnt, sum, t[c];
bool v;
long long k(long long a) {
    bool q=0;
    long long ans=1, pow=p;
    while(a) {
        if (a%2) ans*=pow;
        if (ans>c) q=1;
        ans%=mod, pow*=pow, pow=min(pow, c);
        a/=2;
    }
    if (q) return c;
    else return ans;
}
long long h(long long a) {
    long long ans=1, pow=p;
    while(a) {
        if (a%2) ans*=pow, ans%=mod;
        pow*=pow, pow%=mod;
        a/=2;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> p, cnt=1, sum=0, v=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        sort(t+1, t+n+1), reverse(t+1, t+n+1);
        for (int i=2; i<=n; i++) {
            if (cnt*k(t[i-1]-t[i])>=c) v=true;
            if (v) {
                sum=cnt*h(t[i-1]);
                for (int j=i; j<=n; j++) sum-=h(t[j]);
                sum+=mod*mod;
                sum%=mod;
                break;
            }
            cnt*=h(t[i-1]-t[i]);
            if (cnt>0) cnt--;
            else cnt++;
        }
        if (!v) cnt*=h(t[n]), cnt%=mod, cout << cnt << "\n";
        else cout << sum << "\n";
    }
    return 0;
}