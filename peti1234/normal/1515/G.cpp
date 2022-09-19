#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m;
vector<int> sz[c], s[c], rev[c];
bool v[c], v2[c], v3[c];
int comp[c], csz;
long long tav[c], ans[c];
vector<int> sor;
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    sor.push_back(a);
}
void dfs2(int a) {
    v2[a]=true;
    for (int x:rev[a]) {
        if (!v2[x]) {
            comp[x]=comp[a];
            dfs2(x);
        }
    }
}
void dfs3(int a) {
    v3[a]=true;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (comp[a]!=comp[x]) {
            continue;
        }
        long long suly=s[a][i];
        if (!v3[x]) {
            tav[x]=tav[a]+suly;
            dfs3(x);
        } else {
            ans[comp[x]]=__gcd(ans[comp[x]], abs(tav[a]+suly-tav[x]));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz[a].push_back(b), s[a].push_back(c);
        rev[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            dfs(i);
        }
    }
    while (sor.size()>0) {
        int a=sor.back();
        sor.pop_back();
        if (!v2[a]) {
            comp[a]=++csz;
            dfs2(a);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!v3[i]) {
            dfs3(i);
        }
    }
    for (int i=1; i<=n; i++) {
        //cout << i << " " << ans[comp[i]] << "\n";
    }
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (b==0) {
            cout << "YES\n";
            continue;
        }
        long long s=ans[comp[a]];
        if (!s) {
            cout << "NO\n";
        } else {
            long long p1=__gcd(b, c), p2=__gcd(s, c);
            if (p1%p2==0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
/*
3 4
1 2 1
2 3 1
1 3 2
3 1 1
*/