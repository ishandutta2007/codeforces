#include <bits/stdc++.h>

using namespace std;
const int c=2100002, k=1048576;
int n, m, ans, t[c], lp[c], kezd[c], veg[c];
long long sum=1;
vector<pair<int, pair<int, int> > > sz;
void add(int a, int k, int v) {
    int h=(veg[a]-kezd[a]+1)/2, x=2*a, y=2*a+1;
    if (kezd[a]>v || veg[a]<k) return;
    if (k<=kezd[a] && veg[a]<=v) lp[a]++;
    else {
        add(x, k , v), add(y, k, v);
        t[a]=t[x]+h*lp[x]+t[y]+h*lp[y];
    }
}
int ask(int a, int p) {
    int h=veg[a]-kezd[a]+1, x=2*a, y=2*a+1;
    if (kezd[a]>p || veg[a]<p) return 0;
    if (p<=kezd[a] && veg[a]<=p) return t[a]+h*lp[a];
    else {
        lp[x]+=lp[a], lp[y]+=lp[a], lp[a]=0;
        t[a]=ask(x, p)+ask(y, p);
        return t[a];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=k; i<2*k; i++) kezd[i]=i-k+1, veg[i]=i-k+1;
    for (int i=k-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c-b==1e6) sum++;
        sz.push_back({a, {b, c}});
    }
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c-b==1e6) sum++;
        sz.push_back({b, {-1, -a}}), sz.push_back({c+1, {-1, a}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<sz.size(); i++) {
        int a=sz[i].first, b=sz[i].second.first, c=sz[i].second.second;
        if (b!=-1) add(1, b, c);
        else {
            int x=ask(1, abs(c));
            if (c<0) x*=-1;
            sum+=x;
        }
    }
    cout << sum << "\n";
    return 0;
}