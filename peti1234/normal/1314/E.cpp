#include <bits/stdc++.h>

using namespace std;
long long n, k, mod=998244353, dp[2021], ans;
vector<int> sz;
bool jo(const vector<int> &a, int db) {
    int sum=0, si=a.size(), pos=0;
    for (int x:a) sum+=x;
    if (sum>n) return 0;
    if (db==k-1) return ++ans;
    vector<int> kov(sum, 0);
    for (int i=si-1; i>=0; i--) for (int j=1; j<=a[i]; j++) kov[pos++]=si-i;
    return jo(kov, db+1);
}
void dfs(int a) {
    for (int i=a; i<=n; i++) {
        sz.push_back(i);
        if (jo(sz, 0)) {
            dfs(i);
            sz.pop_back();
        } else {
            sz.pop_back();
            return;
        }
    }
}
int main()
{
    cin >> n >> k;
    if (k<=2) {
        dp[0]=1;
        for (int i=1; i<=n; i++) {
            int ert=(k==1 ? i : i*(i+1)/2);
            for (int j=0; j<=n-ert; j++) {
                dp[j+ert]+=dp[j];
                dp[j+ert]%=mod;
            }
        }
        for (int i=1; i<=n; i++) ans+=dp[i];
    }
    if (k>=3) dfs(1);
    cout << ans%mod << "\n";
    return 0;
}