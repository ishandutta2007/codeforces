#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=524288;
ll n, m, bal[2*c], jobb[2*c], t[c], p[c], k[c], o=0, lp[2*c], sok=1e16;
bool f;
void add(ll a, ll st, ll fi, ll ert) {
    if (st>jobb[a] || fi<bal[a]) return;
    if (st<=bal[a] && jobb[a]<=fi) lp[a]+=ert;
    else add(2*a, st, fi, ert), add(2*a+1, st, fi, ert);
}
void cl(ll a, ll x) {
    if (x>jobb[a] || x<bal[a]) return;
    if (a>=c) return;
    lp[2*a]+=lp[a], lp[2*a+1]+=lp[a], lp[a]=0;
    cl(2*a, x), cl(2*a+1, x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> t[i];
    for (ll i=1; i<=n; i++) cin >> p[i];
    cin >> m, k[m+1]=sok;
    for (ll i=1; i<=m; i++) {
        cin >> k[i];
        if (k[i]<k[i-1]) f=true;
    }
    for (ll i=c; i<2*c; i++) bal[i]=i-c, jobb[i]=i-c;
    for (ll i=c-1; i>=1; i--) bal[i]=bal[2*i], jobb[i]=jobb[2*i+1];
    add(1, 1, m, sok);
    for (ll i=1; i<=n; i++) {
        ll a=t[i], b=p[i], x=0, y=m+1;
        while(y-x>1) {
            ll z=(x+y)/2;
            if (k[z]>=a) y=z;
            else x=z;
        }
        if (k[y]==a) {
            cl(1, x), cl(1, y);
            lp[c+y]=min(lp[c+y]+min(o, b), lp[c+x]);
        } else if (b<0) add(1, y, y, b);
        add(1, 0, x, b);
        if (b<0) add(1, y+1, m, b);
    }
    cl(1, m);
    if (lp[c+m]>sok/10) f=true;
    if (f) cout << "NO" << "\n";
    else cout << "YES\n" << lp[c+m] << "\n";
    return 0;
}