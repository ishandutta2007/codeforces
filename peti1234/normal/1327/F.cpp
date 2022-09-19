#include <bits/stdc++.h>

using namespace std;
long long mod=998244353, ans=1, sum=0;
int n, k, m, db[500002];
long long un[500001];
vector<pair<pair<int, int>, int> > sz;
vector<pair<int, int> > kell;
long long solve(int x) {
    int pr=0, ue=0;
    kell.clear();
    for (int i=0; i<=n; i++) un[i]=0, db[i]=0;
    for (int i=0; i<m; i++) {
        int fi=sz[i].first.second, se=sz[i].first.first, id=sz[i].second;
        if (id&x) db[fi]++, db[se+1]--;
        else kell.push_back({se, fi});
    }
    kell.push_back({n+1, n+1});
    sort(kell.begin(), kell.end());
    for (int i=1; i<=n; i++) db[i]+=db[i-1];
    un[0]=1, sum=1;
    for (int i=1; i<=n; i++) {
        int maxi=0;
        while(kell[pr].first==i) maxi=max(maxi, kell[pr].second), pr++;
        if (db[i]==0) un[i]=sum, sum*=2, sum%=mod;
        for (int i=ue; i<maxi; i++) sum-=un[i], un[i]=0;
        ue=max(ue, maxi), sum+=(mod*mod), sum%=mod;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz.push_back({{b, a},c});
    }
    sz.push_back({{n+1, n+1}, 0});
    sort(sz.begin(), sz.end());
    for (int j=1; j<(1<<k); j*=2) {
        ans*=solve(j), ans%=mod;
    }
    cout << ans << endl;
    return 0;
}