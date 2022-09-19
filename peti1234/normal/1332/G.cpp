#include <bits/stdc++.h>

using namespace std;
const int c=200002, p=524288;
int n, w, si;
int t[c], ek[c], en[c], uk[c], un[c], ans[c], ki[c];
int kezd[2*p+1], veg[2*p+1], sz[2*p+1];
vector<int> kis, nagy;
vector<pair<int, pair<int, int> > > kul, szam;
int f(int id, int st, int er) {
    if (sz[id]>er) {
        if (veg[id]<st) return c;
        if (kezd[id]<st) return (min(f(2*id, st, er), f(2*id+1, st, er)));
        if (id>=p) return kezd[id];
        if (sz[2*id]>er) return f(2*id, st, er);
        return f(2*id+1, st, er);
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    for (int i=1; i<=n; i++) {
        cin >> t[i], ans[i]=n+1;
        if (t[i]!=t[i-1]) szam.push_back({t[i], {i, i}});
        else szam.back().second.second++;
    }
    si=szam.size();
    for (int i=1; i<si-1; i++) {
        int a=szam[i].first, b=szam[i-1].first, c=szam[i+1].first;
        if (a>max(b, c) || a<min(b, c)) kul.push_back({szam[i].second.first, {szam[i-1].second.second, szam[i+1].second.first}});
    }
    for (int i=1; i<=n; i++) {
        while(kis.size()>0 && t[i]>=t[kis.back()]) kis.pop_back();
        if (kis.size()>0) en[i]=kis.back();
        while(nagy.size()>0 && t[i]<=t[nagy.back()]) nagy.pop_back();
        if (nagy.size()>0) ek[i]=nagy.back();
        kis.push_back(i), nagy.push_back(i);
    }
    kis.clear(), nagy.clear();
    for (int i=n; i>=1; i--) {
        while(kis.size()>0 && t[i]>=t[kis.back()]) kis.pop_back();
        if (kis.size()>0) un[i]=kis.back();
        while(nagy.size()>0 && t[i]<=t[nagy.back()]) nagy.pop_back();
        if (nagy.size()>0) uk[i]=nagy.back();
        kis.push_back(i), nagy.push_back(i);
        if (!un[i]) un[i]=c;
        if (!uk[i]) uk[i]=c;
    }
    for (int i=1; i<=n; i++) sz[i+p-1]=min(ek[i], en[i]);
    for (int i=1; i<=p; i++) kezd[i+p-1]=i, veg[i+p-1]=i;
    for (int i=p-1; i>=1; i--) sz[i]=max(sz[2*i], sz[2*i+1]), kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    for (int i=1; i<=n; i++) {
        int x=max(un[i], uk[i]);
        ans[i]=f(1, x+1, i);
    }
    for (int i=n-1; i>=1; i--) {
        if (ans[i]>ans[i+1]) ki[i]=ki[i+1], ans[i]=ans[i+1];
        else ki[i]=i;
    }
    for (int i=1; i<=w; i++) {
        int a, b;
        cin >> a >> b;
        if (ans[a]<=b) {
            int p=ki[a];
            cout << 4 << "\n" << p << " ";
            if (t[p]<t[ans[p]]) cout << min(uk[p], en[ans[p]]) << " " << max(uk[p], en[ans[p]]) << " ";
            else cout << min(un[p], ek[ans[p]]) << " " << max(un[p], ek[ans[p]]) << " ";
            cout << ans[p] << "\n";
        } else {
            bool c=false;
            int l=-1, h=kul.size();
            while(h-l>1) {
                int m=(h+l)/2, aa=kul[m].second.first, bb=kul[m].first, cc=kul[m].second.second;
                if (a<=aa && cc<=b) {
                    cout << 3 << "\n" << aa << " " << bb << " " << cc << "\n";
                    c=true;
                    break;
                }
                if (cc>b) h=m;
                else l=m;
            }
            if (!c) cout << 0 << "\n";
        }
    }
    return 0;
}