#include <bits/stdc++.h>

using namespace std;
long long n, m, q, a[100002], sum, ert, x, sol[100002], sok=1000000000000000001;
vector<pair<long long, long long> > sz;
vector<long long> pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (long long i=1; i<=n; i++) {
        long long x;
        cin >> x;
        if (i%2==0) x*=-1;
        sum+=x;
    }
    for (long long i=1; i<=m; i++) cin >> a[i];
    for (long long i=1; i<=n; i++) {
        if (i%2) ert+=a[i];
        else ert-=a[i];
    }
    pos.push_back(ert), pos.push_back(sok), pos.push_back(-sok), sz.push_back({sum, 0});
    for (long long i=n+1; i<=m; i++) {
        ert-=a[i-n];
        ert*=-1;
        if (n%2) ert+=a[i];
        else ert-=a[i];
        pos.push_back(ert);
    }
    for (long long i=1; i<=q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a%2 && b%2) sum+=c;
        if (a%2==0 && b%2==0) sum-=c;
        sz.push_back({sum, i});
    }
    sort(sz.begin(), sz.end()), sort(pos.begin(), pos.end());
    for (long long i=1; i<pos.size(); i++) {
        while(x<q+1) {
            bool c=0;
            long long fi=sz[x].first, se=sz[x].second;
            if (pos[i-1]<=fi && fi<pos[i]) sol[se]=min(pos[i]-fi, fi-pos[i-1]), x++, c=1;
            if (!c) break;
        }
    }
    for (long long i=0; i<=q; i++) cout << sol[i] << "\n";
    return 0;
}