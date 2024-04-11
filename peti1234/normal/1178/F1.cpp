#include <bits/stdc++.h>

using namespace std;
long long dp[1010][1010];
long long komm[1010][1010];
int n, m;
vector<int> t[501];
vector<int> v;
long long mod=998244353;
long long solve(int a, int b);
long long kom(int a, int b)
{
    if (komm[a][b]!=0) {
        return komm[a][b];
    }
    long long ans=0;
    for (int i=a; i<=b; i++) {
        ans+=solve(a, i-1)*solve(i, b-1);
        ans%=mod;
    }
    komm[a][b]=ans;
    return ans;
}
long long solve(int a, int b)
{
    if (dp[a][b]!=0) {
        return dp[a][b];
    }
    if (a>=b) {
        dp[a][b]=1; // NEM BIZTOS
        return 1;
    }
    int pos=v[a];
    for (int i=a; i<=b; i++){
        if (v[i]<pos) {
            pos=v[i];
        }
    }
    long long sum=1;
    long long ans=0;
    int x=t[pos][0];
    int y=t[pos].back();
    ans=kom(a, x);
    sum*=ans;
    ans=0;
    ans=kom(y+1, b+1);
    sum*=ans;
    sum%=mod;
    ans=0;
    for (int i=1; i<t[pos].size(); i++) {
        x=t[pos][i-1];
        y=t[pos][i];
        ans=solve(x+1, y-1);
        sum*=ans;
        sum%=mod;
    }
    dp[a][b]=sum;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    v.push_back(0);
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        if (x!=v.back()) {
            v.push_back(x);
        }
    }
    m=v.size()-1;
    for (int i=1; i<=m; i++) {
        t[v[i]].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        for (int j=t[i][0]; j<t[i].back(); j++) {
            if (v[j]<i) {
                cout << 0;
                return 0;
            }
        }
    }
    solve(1, m);
    cout << dp[1][m] << endl;
    return 0;
}
// n sznek szma
// m papr hossza sszesen