#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, a, b, c, ks, ns, mini=1e18, t[100002];
void pr(ll x) {
    ll p=0, q=0;
    for (int i=1; i<=n; i++)
        if (t[i]<x) p+=x-t[i];
        else q+=t[i]-x;
    ll f=min(p, q), d=p-f, e=q-f;
    mini=min({mini, a*d+b*e+c*f});
}
int main()
{
    cin >> n >> a >> b >> c;
    for (int i=1; i<=n; i++) cin >> t[i], ns+=t[i];
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        ks+=t[i], ns-=t[i];
        ll p=i*t[i]-ks, q=ns-(n-i)*t[i], f=min(p, q), d=p-f, e=q-f;
        mini=min({mini, p*a+q*b, a*d+b*e+c*f});
    }
    pr(ks/n), pr(ks/n+1);
    cout << mini << "\n";
    return 0;
}