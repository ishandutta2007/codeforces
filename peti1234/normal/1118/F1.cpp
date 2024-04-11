#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, k, fix[c], fel[c], szint[c];
vector<int> sz[c], s[c];
long long ans=1, mod=998244353;
bool v[c];
void dfs(int a) {
    for (auto x:sz[a]) {
        if (!szint[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        }
    }
}
void ns() {
    cout << "0\n";
    exit(0);
}
int fixdb=0, rossz;
pair<long long, long long> solve(int a) {
    if (fix[a]) {
        fixdb++;
        return {1, 0};
    }
    v[a]=true;
    pair<long long, long long> res={0, 1};
    for (auto x:sz[a]) {
        if (!v[x]) {
            pair<long long, long long> p=solve(x);
            res.first=(res.first*(p.first+p.second)+res.second*p.first)%mod;
            res.second=res.second*(p.first+p.second)%mod;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    //cin >> k;
    k=2;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x) s[x].push_back(i);
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    for (int i=1; i<=k; i++) {
        int a=s[i][0];
        for (auto x:s[i]) {
            int b=x;
            if (fix[b] && fix[b]!=i) ns();
            fix[b]=i;
            while (a!=b) {
                if (szint[a]>szint[b]) {
                    a=fel[a];
                    if (fix[a]) {
                        if (fix[a]!=i) ns();
                        break;
                    }
                    fix[a]=i;
                } else {
                    b=fel[b];
                    if (fix[b]) {
                        if (fix[b]!=i) ns();
                        break;
                    }
                    fix[b]=i;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v[i] && !fix[i]) {
            long long s=solve(i).first;
            if (fixdb>1) {
                rossz++;
            }
            fixdb=0;
            ans=ans*s%mod;
        }
    }
    cout << ans << "\n";

    return 0;
}