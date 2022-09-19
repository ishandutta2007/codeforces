#include <bits/stdc++.h>

using namespace std;
const int c=262144, f=c/2;
vector<int> sz[c];
int n, kezd[c], veg[c], t[c], lp[c];
int ask(int a, int pos) {
    if (kezd[a]>pos || veg[a]<pos) return 0;
    if (a>=f) return max(t[a], lp[a]);
    int x=2*a, y=2*a+1;
    lp[x]=max(lp[x], lp[a]), lp[y]=max(lp[y], lp[a]);
    return ask(x, pos)+ask(y, pos);
}
void add(int a, int s, int f) {
    if (kezd[a]>f || veg[a]<s) return;
    if (s<=kezd[a] && veg[a]<=f) lp[a]=max(lp[a], f);
    else add(2*a, s, f), add(2*a+1, s, f);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n+2; i++) sz[i].push_back(0);
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        sz[x].push_back(i);
    }
    for (int i=1; i<=n+2; i++) sz[i].push_back(n+1);
    for (int i=f; i<c; i++) kezd[i]=i-f, veg[i]=i-f, t[i]=i-f;
    for (int i=f-1; i; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    for (int i=1; i<=n+2; i++) {
        int jo=0;
        for (int j=1; j<sz[i].size(); j++) {
            int el=sz[i][j-1], p=sz[i][j];
            if (ask(1, el+1)<p) jo=1;
            add(1, el+1, p);
        }
        if (!jo) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}