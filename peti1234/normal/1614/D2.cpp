#include <bits/stdc++.h>

using namespace std;
const int c=20000005;
int w, n;
long long dp[c], db[c], maxi;
bool pr2[c];
vector<int> pr;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (!pr2[i]) {
            pr.push_back(i);
            for (int j=2*i; j<c; j+=i) pr2[j]=1;
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (auto j:pr) {
        for (int i=(c-1)/j; i>=1; i--) {
            db[i]+=db[i*j];
        }
    }

    for (int i=c-5; i>=1; i--) {
        dp[i]+=db[i]*i;
        for (auto j:pr) {
            if (i*j>=c) break;
            dp[i]=max(dp[i], dp[i*j]+(db[i]-db[i*j])*i);
        }
        maxi=max(maxi, dp[i]);
    }
    cout << maxi << "\n";
    return 0;
}