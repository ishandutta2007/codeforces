#include <bits/stdc++.h>

using namespace std;
const int c=1502;
int n, t[c], ans[c], rf[c], pos=1, most;
long long x[c], y[c];
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    rf[a]=1;
    v[a]=1;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            rf[a]+=rf[x];
        }
    }
}
int irany(int a, int b, int c) {
    long long s=(x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]);
    if (s<0) {
        return -1;
    }
    if (s==0) {
        return 0;
    }
    if (s>0) {
        return 1;
    }
}
int f(int a, int b) {
    return irany(most, a, b)==1;
}
void solve(int cs, int kezd, int veg) {
    most=t[kezd];
    ans[most]=cs;
    if (rf[cs]==1) {
        return;
    }
    sort(t+kezd+1, t+veg+1, f);
    int p=kezd+1;
    for (int x:sz[cs]) {
        if (rf[x]<rf[cs]) {
            solve(x, p, p+rf[x]-1);
            p+=rf[x];
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
        t[i]=i;
        if (x[i]<x[pos]) {
            pos=i;
        }
    }
    swap(t[1], t[pos]);
    solve(1, 1, n);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}