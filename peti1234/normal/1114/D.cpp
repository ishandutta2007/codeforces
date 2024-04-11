#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
bool x[5001][5001];
int dp[5001][5001];
int ri[5001][5001];
int mini;
int solve(int a, int b)
{
    if (a<1 || b>n) {
        return 0;
    }
    if (x[a][b]) {
        return dp[a][b];
    }
    int ans=solve(a-1, b);
    int k=ri[b][v[a]];
    if (k!=0) {
        ans=max(ans, 1+solve(a-1, k+1));
    }
    dp[a][b]=ans;
    x[a][b]=true;
    return ans;
}
int main()
{
    cin >> n;
    v.push_back(0);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x!=v.back()) {
            v.push_back(x);
        }
    }
    n=v.size()-1;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            if (ri[i][v[j]]==0) {
                ri[i][v[j]]=j;
            }
        }
    }
    mini=n-1;
    for (int i=2; i<n; i++) {
        int z=solve(i-1, i+1);
        mini=min(mini, n-1-z);
    }
    cout << mini << endl;
    return 0;
}