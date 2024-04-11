#include <bits/stdc++.h>

using namespace std;
#define lsb(i) (i&(-i))
const int c=524288, k=c/2;
long long sum[c], lp[c], cnt=1;
int n, m, mini=c, pos=0, t[c], kezd[c], veg[c];
void add(int a, int l, int r, int ert) {
    if (l>veg[a] || r<kezd[a]) {
        return;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        lp[a]+=ert;
        return;
    }
    int x=2*a, y=2*a+1, h=veg[x]-kezd[x]+1;
    add(x, l, r, ert), add(y, l, r, ert);
    sum[a]=sum[x]+sum[y]+h*(lp[x]+lp[y]);
    return;
}
int ask(int a, int ert) {
    if (a>=k) {
        return kezd[a];
    }
    int x=2*a, y=2*a+1, h=veg[x]-kezd[x]+1;
    lp[x]+=lp[a], lp[y]+=lp[a], sum[a]+=lp[a]*2*h, lp[a]=0;
    long long s=sum[x]+h*lp[x];
    if (s>=ert) {
        return ask(x, ert);
    }
    return ask(y, ert-s);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1), reverse(t+1, t+n+1);
    for (int i=k; i<c; i++) {
        kezd[i]=i-k, veg[i]=i-k;
    }
    for (int i=k-1; i; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
    add(1, 0, 0, 1);
    for (int i=1; i<=n; i++) {
        cnt+=t[i]-2, t[i]--;
        add(1, pos, pos, -1);
        add(1, pos+2, pos+2+t[i]/2-1, 1);
        add(1, pos+2, pos+2+t[i]-t[i]/2-1, 1);
        pos=ask(1, 1);
        if (cnt>=m) {
            mini=min(mini, ask(1, m));
        }
    }
    cout << (cnt<m ? -1 : mini) << "\n";
    return 0;
}