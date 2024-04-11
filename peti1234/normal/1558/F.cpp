#include <bits/stdc++.h>

using namespace std;
const int c=(1<<19);
int w, n, t[c], inv[c];
int kezd[c], veg[c], sum[c], maxi[c];
void init(int n) {
    int po=1;
    while (po<=n) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=i-po+1;
        sum[i]=0, maxi[i]=0;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
        sum[i]=0, maxi[i]=0;
    }
}
int f(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return 2;
    }
    return 1;
}

void add(int a, int l, int r, int val) {
    int s=f(a, l, r);
    if (!s) {
        return;
    }
    if (s==2) {
        sum[a]+=val;
        maxi[a]+=val;
        return;
    }
    int x=2*a, y=2*a+1;
    add(x, l, r, val), add(y, l, r, val);
    maxi[a]=max(maxi[x], maxi[y])+sum[a];
}

int ask(int a, int l, int r) {
    int s=f(a, l, r);
    if (!s) {
        return 0;
    }
    if (s==2) {
        return maxi[a];
    }
    int x=2*a, y=2*a+1;
    return max(ask(x, l, r), ask(y, l, r))+sum[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            inv[t[i]]=i;
        }
        init(n);
        for (int i=1; i<=n; i++) {
            add(1, i, i, -2*c+i-1+i%2);
        }
        int ans=0, pos=1;
        for (int i=1; i<=n; i++) {
            int s=inv[i];
            add(1, s, s, 2*c);
            add(1, s+1, n, -1);
            add(1, 1, s-1, 1);
            while (pos<=n && t[pos]<=i) {
                pos++;
            }
            ans=max(ans, ask(1, pos, n));
        }

        cout << ans << "\n";
    }
    return 0;
}