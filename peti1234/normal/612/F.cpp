#include <bits/stdc++.h>

using namespace std;
const int c=4005, sok=2e9;
int n, st, t[c], dp[c], ki[c], dir[c], ert;
vector<int> a, ans;
map<int, vector<int> > m;
int tav(int a, int b) {
    int s=(a-b+3*n)%n;
    return min(s, n-s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> st;
    st=st-1+n;
    m[-sok].push_back(st);
    for (int i=0; i<n; i++) {
        cin >> t[i];
        m[t[i]].push_back(i);
    }
    for (auto x:m) a.push_back(x.first), sort(x.second.begin(), x.second.end());
    for (int i=0; i<n; i++) dp[i]=sok;
    int si=a.size();
    for (int i=0; i<si-1; i++) {
        vector<int> kezd=m[a[i]], veg=m[a[i+1]];
        int vs=veg.size();
        for (auto x:kezd) {
            for (int s=0; s<veg.size(); s++) {
                int pos=veg[s], el=veg[(s-1+vs)%vs], kov=veg[(s+1)%vs];
                if (vs==1) {
                    if (dp[pos]>dp[x]+tav(x, pos)) {
                        dp[pos]=dp[x]+tav(x, pos);
                        ki[pos]=x;
                        dir[pos]=1;
                    }
                } else {
                    int pe=(el>pos ? el-pos : el+n-pos), pk=(pos>kov ? pos-kov : pos+n-kov);
                    if (dp[pos]>dp[x]+tav(x, el)+pe) {
                        dp[pos]=dp[x]+tav(x, el)+pe;
                        ki[pos]=x;
                        dir[pos]=1;
                    }
                    if (dp[pos]>dp[x]+tav(x, kov)+pk) {
                        dp[pos]=dp[x]+tav(x, kov)+pk;
                        ki[pos]=x;
                        dir[pos]=-1;
                    }
                }
            }
        }
    }
    ert=m[a.back()][0];
    for (auto x:m[a.back()]) {
        if (dp[x]<dp[ert]) {
            ert=x;
        }
    }
    /*for (int i=0; i<n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";*/
    cout << dp[ert] << "\n";
    while (ert!=st) {
        int d=dir[ert];
        vector<int> veg=m[t[ert]];
        int pos=-1, si=veg.size();
        for (int i=0; i<si; i++) if (veg[i]==ert) pos=i;
        for (int i=0; i<si; i++) ans.push_back({veg[(pos+d*i+si)%si]});
        ert=ki[ert];
    }
    ans.push_back(st-n);
    reverse(ans.begin(), ans.end());
    for (int i=0; i<n; i++) {
        int a=ans[i], b=ans[i+1];
        int ert=(b-a+n)%n;
        cout << (2*ert<=n ? "+" : "-");
        cout << tav(a, b) << "\n";
    }
    return 0;
}