#include <bits/stdc++.h>

using namespace std;
const long long mod=1e9+7, c=131072, f=2*c, gy=448, p=86;
//const long long mod=1e9+7, c=131072, f=2*c, gy=0, p=0;
bool pr[gy];
long long ans;
vector<int> kp, l, u(p, 0), s;
int n, q, t[c], kezd[f], veg[f], ut[f];
vector<int> kis[f], kom[f];
vector<pair<int, int> > nagy[f];
void ks(int a, int x, int y) {
    if (veg[a]<x || y<kezd[a]) return;
    if (x<=kezd[a] && veg[a]<=y) {
        for (int i=0; i<p; i++) {
            s[i]=max(s[i], kis[a][i]);
        }
        return;
    }
    ks(2*a, x, y);
    ks(2*a+1, x, y);
}
void ns(int a, int x, int y) {
    if (veg[a]<x || y<kezd[a]) return;
    if (x<=kezd[a] && veg[a]<=y) {
        int lo=-1, hi=nagy[a].size();
        while(hi-lo>1) {
            int mid=(hi+lo)/2;
            if (nagy[a][mid].first<x) lo=mid;
            else hi=mid;
        }
        if (lo!=-1) {
            ans*=kom[a][lo], ans%=mod;
        }
        return;
    }
    ns(2*a, x, y);
    ns(2*a+1, x, y);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    for (int i=c; i<f; i++) kezd[i]=i-c, kis[i]=u, veg[i]=i-c;
    for (int i=c-1; i>=1; i--) kezd[i]=kezd[2*i], kis[i]=u, veg[i]=veg[2*i+1];
    for (int i=2; i<gy; i++) {
        if (!pr[i]) {
            kp.push_back(i);
            for (int j=2*i; j<gy; j+=i) pr[j]=1;
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        s=u;
        for (int j=0; j<p; j++) {
            while(t[i]%kp[j]==0) {
                s[j]++, t[i]/=kp[j];
            }
        }
        kis[i+c]=s;
        for (int j=0; j<p; j++) {
        }
        nagy[i+c].push_back({ut[t[i]], t[i]});
        kom[i+c].push_back(t[i]);
        ut[t[i]]=i;
    }
    for (int i=c-1; i>=1; i--) {
        for (int j=0; j<p; j++) {
            kis[i][j]=max(kis[2*i][j], kis[2*i+1][j]);
        }
        int pos=0;
        for (int j=0; j<nagy[2*i].size(); j++) {
            while(pos<nagy[2*i+1].size() && nagy[2*i+1][pos].first<nagy[2*i][j].first) nagy[i].push_back(nagy[2*i+1][pos]), pos++;
            nagy[i].push_back(nagy[2*i][j]);
        }
        while(pos<nagy[2*i+1].size()) nagy[i].push_back(nagy[2*i+1][pos]), pos++;
        long long pr=1;
        for (int j=0; j<nagy[i].size(); j++) {
            pr*=nagy[i][j].second, pr%=mod;
            kom[i].push_back(pr);
        }
    }
    cin >> q;
    for (int i=1; i<=q; i++) {
        int a, b; cin >> a >> b;
        a=(a+ans)%n+1, b=(b+ans)%n+1;
        if (a>b) swap(a, b);
        ans=1;
        s=u;
        ks(1, a, b);
        for (int i=0; i<p; i++) {
            for (int j=0; j<s[i]; j++) {
                ans*=kp[i], ans%=mod;
            }
        }
        ns(1, a, b);
        cout << ans << "\n";
    }
    return 0;
}
/*
3
2 3 5
1
1 2
*/