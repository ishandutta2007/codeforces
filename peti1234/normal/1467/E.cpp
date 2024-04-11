#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, cnt, cl[c], ossz[c], ut[c], f[c], rf[c], pos, ans, comp, kozep;
vector<int> sz[c];
map<int, int> m;
bool v[c], jo[c], spec[c];
int dfs(int a) {
    v[a]=true;
    ut[cl[a]]=a;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            int s=dfs(x);
            if (s) {
                return s;
            }
        }
    }
    int s=ut[cl[a]];
    if (s!=a) {
        return f[s];
    }
    return 0;
}
void spec_dfs(int a) {
    if (!spec[a]) {
        return;
    }
    ans++;
    spec[a]=0;
    for (int x:sz[a]) {
        if (spec[x]) {
            spec_dfs(x);
        }
    }
}
void jo_dfs(int a) {
    v[a]=true;
    comp++;
    for (int x:sz[a]) {
        if (jo[x] && !v[x]) {
            jo_dfs(x);
        }
    }
}
void cent_dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (int x:sz[a]) {
        if (jo[x] && !v[x]) {
            cent_dfs(x);
            rf[a]+=rf[x];
        }
    }
    if (!kozep && 2*rf[a]>=comp) {
        kozep=a;
    }
}
int cent(int a) {
    for (int i=1; i<=n; i++) {
        v[i]=0;
    }
    comp=0, kozep=0;
    if (!jo[a]) {
        return 0;
    }
    jo_dfs(a);
    for (int i=1; i<=n; i++) {
        rf[a]=0, v[i]=0;
    }
    cent_dfs(a);
    return kozep;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        if (!m[x]) {
            cnt++;
            m[x]=cnt;
        }
        x=m[x];
        cl[i]=x, ossz[x]++;
    }
    for (int i=1; i<=n; i++) {
        if (ossz[cl[i]]==1) {
            spec[i]=1;
        }
        jo[i]=1;
    }
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    pos=1;
    while(true) {
        pos=cent(pos);
        jo[pos]=0;
        for (int i=1; i<=n; i++) {
            v[i]=0, ut[i]=0, f[i]=0;
        }
        int s=dfs(pos);
        if (s) {
            pos=s;
        } else {
            break;
        }
    }
    spec_dfs(pos);
    cout << ans << "\n";
    return 0;
}