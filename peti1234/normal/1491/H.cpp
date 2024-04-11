#include <bits/stdc++.h>

using namespace std;
const int c=105002, gy=320;
int n, q, t[c], fel[c], lp[c];
int mbl[c], kezd[c], veg[c], jo[c];
void valt(int a, int b) {
    t[a]=max(1, t[a]-b);
}
int kov(int a) {
    return max(1, t[a]-lp[mbl[a]]);
}
void solve(int bl, int ert) {
    if (jo[bl]) {
        lp[bl]+=ert;
        lp[bl]=min(lp[bl], n);
        return;
    }
    bool sp=1;
    for (int i=kezd[bl]; i<=veg[bl]; i++) {
        valt(i, ert);
        int s=kov(i);
        if (mbl[s]!=mbl[i]) {
            fel[i]=i;
        } else {
            fel[i]=fel[s];
            sp=0;
        }
    }
    if (sp) {
        jo[bl]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        mbl[i]=mbl[i-1]+(((i-1)%gy)==0);
    }
    for (int i=1; i<=n; i++) {
        kezd[i]=(i-1)*gy+1, veg[i]=i*gy;
    }
    for (int i=2; i<=n; i++) {
        cin >> t[i];
    }

    for (int i=1; kezd[i]<=n; i++) {
        solve(i, 0);
    }
    for (int i=1; i<=q; i++) {
        int s;
        cin >> s;
        if (s==1) {
            int l, r, x;
            cin >> l >> r >> x;
            int kb=mbl[l], nb=mbl[r];
            if (kb==nb) {
                for (int i=l; i<=r; i++) {
                    valt(i, x);
                }
                solve(kb, 0);
            } else {
                while (mbl[l]==kb) {
                    valt(l, x);
                    l++;
                }
                solve(kb, 0);
                while (mbl[r]==nb) {
                    valt(r, x);
                    r--;
                }
                solve(nb, 0);
                for (int i=kb+1; i<nb; i++) {
                    solve(i, x);
                }
            }
        }
        if (s==2) {
            int a, b;
            cin >> a >> b;
            if (a<b) {
                swap(a, b);
            }
            while (fel[a]!=fel[b]) {
                a=kov(fel[a]);
                if (a<b) {
                    swap(a, b);
                }
            }
            while (a!=b) {
                a=kov(a);
                if (a<b) {
                    swap(a, b);
                }
            }
            cout << a << "\n";
        }
    }
    return 0;
}