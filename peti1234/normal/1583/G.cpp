#include <bits/stdc++.h>

using namespace std;
const int c=400005;
long long n, s, kezd[c], veg[c], maxi[c], ert[c], t[c], ans, mod=1e9+7;
vector<pair<int, int> > sz;
int lsb(int a) {
    return (a & -a);
}
void add(int a, int b) {
    while (a<=2*n) {
        t[a]=(t[a]+b)%mod;
        a+=lsb(a);
    }
}
long long ask(int a) {
    long long ans=0;
    while (a) {
        ans=(ans+t[a])%mod;
        a-=lsb(a);
    }
    return ans;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> kezd[i] >> veg[i];
        sz.push_back({veg[i], i});
    }
    cin >> s;
    for (int i=1; i<=s; i++) {
        int x;
        cin >> x;
        maxi[kezd[x]]=veg[x];
    }
    for (int i=2*n-1; i>=1; i--) {
        maxi[i]=max(maxi[i], maxi[i+1]);
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int id=x.second;
        ert[id]=(ask(veg[id])-ask(kezd[id])+mod+1)%mod;
        add(kezd[id], ert[id]);
        if (maxi[kezd[id]]>=veg[id]) {
            ans=(ans+ert[id])%mod;
        }
    }
    cout << ans << "\n";
    return 0;
}