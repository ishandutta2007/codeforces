#include <bits/stdc++.h>

using namespace std;
long long po[1500005], mod=998244353;
long long solve(vector<int> a, vector<int> b, int ert, int k) {
    int sa=a.size(), sb=b.size();
    if (sa==0 || sb==0 || ert==0) {
        return po[sa+sb];
    }
    vector<int> a0, a1, b0, b1;
    for (auto x:a) {
        if (x & ert) a1.push_back(x);
        else a0.push_back(x);
    }
    for (auto y:b) {
        if (y & ert) b1.push_back(y);
        else b0.push_back(y);
    }
    int sa0=a0.size(), sa1=a1.size(), sb0=b0.size(), sb1=b1.size();
    if (ert>k) {
        return (po[sa]+po[sb]+solve(a0, b0, ert/2, k)+solve(a1, b1, ert/2, k)-po[sa0]-po[sa1]-po[sb0]-po[sb1]+1+10*mod)%mod;
    } else {
        return solve(a0, b1, ert/2, k-ert)*solve(a1, b0, ert/2, k-ert)%mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n, k, ert=1, ans=0;
    cin >> n >> k;
    po[0]=1;
    for (int i=1; i<=n; i++) po[i]=po[i-1]*2%mod;
    map<int, vector<int> > a, b;
    set<int> s;
    while (ert<=k) ert*=2;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x & ert/2) a[x/ert].push_back(x);
        else b[x/ert].push_back(x);
        s.insert(x/ert);
    }
    for (auto x:s) {
        ans=(ans+solve(a[x], b[x], ert/2, k)+mod-1)%mod;
    }
    cout << ans << "\n";
    return 0;
}