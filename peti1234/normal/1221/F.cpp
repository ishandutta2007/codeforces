#include <bits/stdc++.h>

using namespace std;
const int c=(1<<21);
long long n, si, kezd[c], veg[c], sum[c], maxi[c], pos[c];
long long xx[c], yy[c], val[c], sok=2e9, ans, bal=sok, jobb=sok;
vector<int> sz;
map<int, int> m;
vector<pair<int, long long> > sor[c];
void init(int ert) {
    int po=1;
    while (po<ert) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=veg[i]=pos[i]=i-po;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
int calc(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return 2;
    }
    return 1;
}
void add(int a, int l, int r, long long ert) {
    int s=calc(a, l, r);
    if (s==0) {
        return;
    }
    if (s==2) {
        sum[a]+=ert;
        maxi[a]+=ert;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, ert), add(y, l, r, ert);
    pos[a]=(maxi[x]>maxi[y] ? pos[x] : pos[y]);
    maxi[a]=sum[a]+max(maxi[x], maxi[y]);
}
pair<long long, int> ask(int a, int l, int r) {
    int s=calc(a, l, r);
    if (s==0) {
        return {-sok, 0};
    }
    if (s==2) {
        return {maxi[a], pos[a]};
    }
    auto p1=ask(2*a, l, r), p2=ask(2*a+1, l, r);
    p1.first+=sum[a], p2.first+=sum[a];
    return max(p1, p2);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> xx[i] >> yy[i] >> val[i];
        sz.push_back(xx[i]), sz.push_back(yy[i]);
    }
    sort(sz.begin(), sz.end());
    sz.erase(unique(sz.begin(), sz.end()), sz.end());
    si=sz.size();
    init(si);
    for (int i=0; i<si; i++) {
        m[sz[i]]=i;
        add(1, i, i, -sz[i]);
    }
    for (int i=1; i<=n; i++) {
        int a=m[xx[i]], b=m[yy[i]];
        if (a>b) {
            swap(a, b);
        }
        sor[a].push_back({b, val[i]});
    }
    for (int i=si-1; i>=0; i--) {
        for (auto x:sor[i]) {
            add(1, x.first, si-1, x.second);
        }
        auto p=ask(1, i, si-1);
        if (sz[i]+p.first>ans) {
            ans=sz[i]+p.first;
            bal=sz[i], jobb=sz[p.second];
        }
    }
    cout << ans << "\n";
    cout << bal << " " << bal << " " << jobb << " " << jobb;
    return 0;
}