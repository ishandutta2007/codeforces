#include <bits/stdc++.h>

using namespace std;
const int c=1<<19, k=c/2, mod=1e9;
long long n, q, kezd[c], veg[c], t[c], t1[c], t2[c], lp[c], fib[c], fkom[c];
long long madd(long long a, long long b) {
    long long ans=a+b;
    if (ans>=mod) ans-=mod;
    return ans;
}
long long db(long long a, long long b) {
    if (lp[a]>=mod) lp[a]-=mod;
    int h=veg[a]-kezd[a]+1;
    if (!b) return (t2[a]+lp[a]*fkom[h-1])%mod;
    long long s=(fkom[b+h-1]-fkom[b-1]+mod)*lp[a]%mod;
    return (fib[b]*t1[a]+fib[b-1]*t2[a]+s)%mod;
}
// t1 : 1, 1, 2, 3, 5...
// t2 : 0, 1, 1, 2, 3...
void calc(int a) {
    int x=2*a, y=2*a+1, h=veg[a]-kezd[a]+1;
    t1[a]=madd(db(x, 1), db(y, h/2+1));
    t2[a]=madd(db(x, 0), db(y, h/2));
}
long long ask(int a, int l, int r) {
    if (lp[a]>=mod) lp[a]-=mod;
    if (kezd[a]>r || veg[a]<l) return 0;
    if (l<=kezd[a] && veg[a]<=r) {
        long long st=kezd[a]-l+1, h=veg[a]-kezd[a]+1;
        return db(a, st);
    }
    int x=2*a, y=2*a+1;
    lp[x]+=lp[a], lp[y]+=lp[a], lp[a]=0;
    calc(a);
    return madd(ask(x, l, r), ask(y, l, r));
}
void add(int a, int l, int r, int ert) {
    if (lp[a]>=mod) lp[a]-=mod;
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) {
        lp[a]+=ert;
        if (lp[a]>=mod) lp[a]-=mod;
        return;
    }
    int x=2*a, y=2*a+1;
    lp[x]+=lp[a], lp[y]+=lp[a], lp[a]=0;
    add(x, l, r, ert), add(y, l, r, ert);
    calc(a);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    fib[1]=1, fkom[1]=1;
    for (int i=2; i<=n; i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
        fkom[i]=(fkom[i-1]+fib[i])%mod;
    }
    for (int i=k; i<c; i++) {
        kezd[i]=i-k+1, veg[i]=i-k+1;
        if (i<k+n) {
            cin >> lp[i];
        }
    }
    for (int i=k-1; i>=1; i--) {
        int a=2*i, b=2*i+1, h=veg[a]-kezd[a]+1;
        kezd[i]=kezd[a], veg[i]=veg[b];
        calc(i);
    }
    for (int i=1; i<=q; i++) {
        int x;
        cin >> x;
        if (x==2) {
            int a, b; cin >> a >> b;
            //cout << "valasz ";
            cout << ask(1, a, b) << "\n";
        }
        if (x==1) {
            int a, b; cin >> a >> b;
            add(1, a, a, 0);
            add(1, a, a, b-lp[a+k-1]);
        }
        if (x==3) {
            int a, b, c;
            cin >> a >> b >> c;
            add(1, a, b, c);
        }
    }
    return 0;
}
/*
4 1
2 4 2 3
2 2 4
*/
/*
4 3
2 4 2 3
2 2 4
1 2 10
2 1 4
*/