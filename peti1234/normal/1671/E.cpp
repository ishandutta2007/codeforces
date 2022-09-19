#include <bits/stdc++.h>

using namespace std;
int n, f, ans=1, mod=998244353;
string s;
string dfs(int x) {
    string p=s.substr(x-1, 1);
    if (x>=f) {
        return p;
    }
    string a=dfs(2*x), b=dfs(2*x+1);
    if (b>a) swap(a, b);
    if (a!=b) {
        ans=2*ans%mod;
    }
    return p+a+b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    f=1<<(n-1);
    dfs(1);
    cout << ans << "\n";
    return 0;
}