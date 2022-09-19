#include <bits/stdc++.h>

using namespace std;
const int c=100005;
const long double eps=1e-8;
long double s=1e6, p, q, ans=s, x[c], y[c];
int n, t[c];
vector<int> sz;
int irany(int a, int b, int c) {
    long double s = (x[b]-x[a])*(y[c]-y[a])-(y[b]-y[a])*(x[c]-x[a]);
    return (s<0 ? -1 : s>0 ? 1 : 0);
}

bool kisebb(int a, int b) {
    return (y[a]<y[b] || (y[a]==y[b] && x[a]<x[b]));
}
bool r(int a, int b) {
    int s=irany(0, a, b);
    return (s==1 || (s==0 && kisebb(a, b)));
}
void ch(int a, int b) {
    if (irany(0, a, b)!=1 || x[a]>=y[a] && x[b]>=y[b] || x[a]<=y[a] && x[b]<=y[b]) {
        return;
    }
    long double lo=x[a], hi=x[b];
    if (lo>hi) {
        swap(hi, lo);
    }
    while (hi-lo>eps) {
        long double mid=(hi+lo)/2;
        x[n+1]=y[n+1]=mid;
        if (irany(a, b, n+1)==1) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    ans=min(ans, s/lo);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;

    for (int i=1; i<=n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        x[i]=xx, y[i]=yy;
        x[i]*=s/p, y[i]*=s/q;
        ans=min(ans, max(s/x[i], s/y[i]));
        t[i]=i;
    }

    sort(t+1, t+n+1, r);
    sz.push_back(0);
    for (int i=1; i<=n; i++) {
        int si=sz.size();
        while (si>1 && irany(sz[si-2], sz[si-1], t[i])!=1) {
            sz.pop_back();
            si--;
        }
        sz.push_back(t[i]);
    }
    int si=sz.size();
    for (int i=1; i<si-1; i++) {
        ch(sz[i], sz[i+1]);
    }

    cout.precision(20);
    cout << ans << "\n";
    return 0;
}