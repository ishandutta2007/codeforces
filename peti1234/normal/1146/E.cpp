#include <bits/stdc++.h>

using namespace std;
const int k=(1<<18), c=k/2;
int n, q, t[c];
int kezd[k], veg[k], lp[k];
void valt(int a, int ert) {
    if (ert==0 || ert==3) {
        lp[a]^=ert;
    } else {
        lp[a]=ert;
    }
}
void add(int a, int l, int r, int ert) {
    /*
    if (a==1) {
        cout << l << " " << r << " " << ert << "\n";
    }
    */
    int bal=kezd[a], jobb=veg[a];
    if (bal>r || jobb<l) {
        return;
    }
    if (l<=bal && jobb<=r) {
        valt(a, ert);
        return;
    }
    int x=2*a, y=2*a+1;
    valt(x, lp[a]), valt(y, lp[a]);
    lp[a]=0;
    add(x, l, r, ert), add(y, l, r, ert);
}
int ask(int a, int l) {
    int bal=kezd[a], jobb=veg[a];
    if (bal>l || jobb<l) {
        return 0;
    }
    if (lp[a]==1 || lp[a]==2) {
        return lp[a];
    }
    if (l<=bal && jobb<=l) {
        return lp[a];
    }
    int x=2*a, y=2*a+1;
    return ask(x, l)^ask(y, l)^lp[a];
}
void init(int po) {
    for (int i=po; i<2*po; i++) {
        kezd[i]=veg[i]=i-po;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i];
        veg[i]=veg[2*i+1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    init(c);
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        char w;
        int x;
        cin >> w >> x;
        if (w=='>') {
            if (x<0) {
                add(1, 0, abs(x)-1, 3);
                add(1, abs(x), c-1, 2);
            } else {
                add(1, x+1, c-1, 2);
            }
        } else {
            if (x>0) {
                add(1, 0, x-1, 3);
                add(1, abs(x), c-1, 1);
            } else {
                add(1, abs(x)+1, c-1, 1);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        int x=t[i], s=ask(1, abs(x));
        if (s==0) {
            cout << x;
        }
        if (s==1) {
            cout << abs(x);
        }
        if (s==2) {
            cout << -abs(x);
        }
        if (s==3) {
            cout << -x;
        }
        cout << " ";
    }
    return 0;
}
/*
11 1
-5 -4 -3 -2 -1 0 1 2 3 4 5
> -2
*/