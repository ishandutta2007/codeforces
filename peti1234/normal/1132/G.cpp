#include <bits/stdc++.h>

using namespace std;
const int c=1000002, f=21, cc=4194304, kk=cc/2;
int n, k, t[c], cnt, be[c], ki[c], kezd[cc], veg[cc], maxi[cc], lp[cc];
vector<int> sz[c], p;
bool v[c];
void dfs(int a) {
    v[a]=true;
    cnt++, be[a]=cnt;
    for (int x:sz[a]) {
        dfs(x);
    }
    cnt++, ki[a]=cnt;
}
void add(int a, int l, int r, int e) {
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) {
        lp[a]+=e;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, e), add(y, l, r, e);
    maxi[a]=max(maxi[x]+lp[x], maxi[y]+lp[y]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        while(p.size()>0 && t[i]>t[p.back()]) {
            sz[i].push_back(p.back());
            p.pop_back();
        }
        p.push_back(i);
    }
    for (int i=n; i; i--) {
        if (!v[i]) {
            dfs(i);
        }
    }
    for (int i=kk; i<cc; i++) kezd[i]=i-kk, veg[i]=i-kk;
    for (int i=kk-1; i; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    for (int i=1; i<k; i++) {
        add(1, be[i], ki[i], 1);
    }
    for (int i=k; i<=n; i++) {
        add(1, be[i], ki[i], 1);
        cout << maxi[1]+lp[1] << " ";
        int s=i-k+1;
        add(1, be[s], ki[s], -1);
    }
    cout << "\n";
    return 0;
}