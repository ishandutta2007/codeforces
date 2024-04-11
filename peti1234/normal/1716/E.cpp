#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<pair<ll, pair<ll, ll> > >
const int c=1000005;
long long n, t[c], pref[c], o;
long long calc(int l, int r) {
    return pref[r+1]-pref[l];
}
vll solve(int l, int r) {
    int len=r-l+1;
    vll ans(len);
    if (len==1) {
        long long x=max(o, t[l]);
        ans[0]={x, {x, x}};
        return ans;
    }
    int koz=(l+r)/2, f=len/2;
    vll bal=solve(l, koz), jobb=solve(koz+1, r);
    long long sb=calc(l, koz), sj=calc(koz+1, r);
    for (int i=0; i<len; i++) {
        if (i==f) swap(bal, jobb), swap(sj, sb);
        int si=(i>=f ? i-f : i);
        long long b1=bal[si].first, b2=bal[si].second.first, b3=bal[si].second.second;
        long long j1=jobb[si].first, j2=jobb[si].second.first, j3=jobb[si].second.second;

        ans[i].first=max({b1, j1, b3+j2});
        ans[i].second.first=max(b2, sb+j2);
        ans[i].second.second=max(j3, sj+b3);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    n=(1<<n);
    for (int i=0; i<n; i++) {
        cin >> t[i];
        pref[i+1]=(pref[i]+t[i]);
    }
    vll ans=solve(0, n-1);
    int q, xo=0;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        xo^=(1<<x);
        cout << ans[xo].first << "\n";
    }
    return 0;
}