#include <bits/stdc++.h>
#define lsb(a) ((a) & (-a))
using namespace std;
const int c=200002;
long long n, db, sum, xsz, ysz, x[c], xk[c], y[c], yk[c], t[c];
vector<pair<int, int> > xr, yr;
vector<int> sz[c];
bool v[c];
void add(int a) {
    if (!v[a]) {
        db++, v[a]=1;
        while(a<c) {
            t[a]++, a+=lsb(a);
        }
    }
}
int ask(int a) {
    int ans=0;
    while(a) {
        ans+=t[a];
        a-=lsb(a);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    xr.push_back({0, 0}), yr.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        xr.push_back({x[i], i});
        yr.push_back({y[i], i});
    }
    sort(xr.begin(), xr.end()), sort(yr.begin(), yr.end());
    for (int i=1; i<=n; i++) {
        sz[i].push_back(0), sz[i].push_back(n+1);
        if (xr[i].first!=xr[i-1].first) xsz++;
        xk[xr[i].second]=xsz;
        if (yr[i].first!=yr[i-1].first) ysz++;
        yk[yr[i].second]=ysz;
    }
    for (int i=1; i<=n; i++) {
        sz[yk[i]].push_back(xk[i]);
        //cout << i << " " << xk[i] << " " << yk[i] << endl;
    }
    for (int i=n; i; i--) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        for (int j=1; j<si; j++) {
            long long dif=ask(sz[i][j]-1)-ask(sz[i][j-1]);
            sum-=dif*(dif+1)/2;
            if (j!=si-1) {
                add(sz[i][j]);
            }
        }
        sum+=db*(db+1)/2;
    }
    cout << sum << "\n";
    return 0;
}