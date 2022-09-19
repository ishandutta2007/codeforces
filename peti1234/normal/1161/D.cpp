#include <bits/stdc++.h>

using namespace std;
long long mod=998244353;
int n;
string ss;
long long sum=0;
int b[2001];
int t[1001];
bool v[2001];
vector<int> sz[2001];
vector<int> s[2001];
void pb(int a, int b, int c)
{
    if (c==-1) {
        return;
    }
    sz[a].push_back(b);
    s[a].push_back(c);
}
int check(int a, int c)
{
    if (b[a]==-1) {
        b[a]=c;
        return -1;
    }
    if (b[a]==c) {
        return 1;
    }
    return 0;
}
bool dfs(int a)
{
    v[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        int y=s[a][i];
        y+=b[a];
        y%=2;
        int c=check(x, y);
        if (c==0) {
            return 0;
        }
        if (c==-1 && !v[x]) {
            if (!dfs(x)) {
                return 0;
            }
        }
    }
    return 1;
}
long long solve(int a)
{
    int e=1000;
    long long ans=1;
    for (int i=1; i<=n+e; i++) {
        sz[i].clear();
        s[i].clear();
        v[i]=false;
        b[i]=-1;
    }
    for (int i=1; i<=n; i++) {
        pb(i, n-i+1, 0);
    }
    for (int i=1; i<=n; i++) {
        pb(i, e+i, t[i]);
        pb(e+i, i, t[i]);
    }
    for (int i=e+a; i<=n+e; i++) {
        pb(i, n+2*e+a-i, 0);
    }
    b[1]=1;
    if (!dfs(1)) {
        return 0;
    }
    for (int i=e+1; i<e+a; i++) {
        int c=check(i, 0);
        if (c==0) {
            return 0;
        }
        if (c==-1) {
            if (!dfs(i)) {
                return 0;
            }
        }
    }
    int c=check(a+e, 1);
    if (c==0) {
        return 0;
    }
    if (c==-1) {
        if (!dfs(a+e)) {
            return 0;
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            b[i]=0;
            if (!dfs(i)) {
                return 0;
            }
            ans*=2;
            ans%=mod;
        }
    }
    for (int i=e+1; i<=e+n; i++) {
        if (!v[i]) {
            b[i]=0;
            if (!dfs(i)) {
                return 0;
            }
            ans*=2;
            ans%=mod;
        }
    }
    return ans;
}
int main()
{
    cin >> ss;
    n=ss.size();
    for (int i=0; i<n; i++) {
        if (ss[i]=='?') {
            t[i+1]=-1;
        }
        if (ss[i]=='1') {
            t[i+1]=1;
        }
    }
    for (int i=1; i<=n; i++) {
        sum+=solve(i);
        sum%=mod;
    }
    cout << sum << endl;
    return 0;
}