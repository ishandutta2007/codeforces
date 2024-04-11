#include <bits/stdc++.h>

using namespace std;
const int c=32;
long long n, q, sum, t[c], o=0, sok=1e18;
long long db[c], w, a, b, kdb, ksum, lep, ans;

void ch() {
    if (kdb>=b) {
        ans=min(ans, lep);
    } else if (ksum>=b) {
        ans=min(ans, lep+b-kdb);
    }
}
void valt(long long id) {
    long long s=(1<<(id-a)), ert=max(o, min(db[id], (b-kdb)/s));
    db[id]-=ert;
    lep+=ert*(1<<(id-a))-ert;
    kdb+=ert*s;
    ksum+=ert*(1<<id);
    ch();
    if (db[id]) {
        if (id==a+1) {
            ans=min(ans, lep+1);
        }
        db[id-1]+=2;
        lep++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=0; i<n;i++) {
        cin >> t[i];
    }
    while (q--) {
        cin >> w >> a >> b;
        if (w==1) {
            t[a]=b;
        } else {
            ans=sok;
            sum=kdb=ksum=lep=0;
            for (int i=0; i<=a; i++) {
                kdb+=t[i];
                ksum+=t[i]*(1<<i);
                sum+=t[i]*(1<<i);
            }
            ch();
            long long pos=0;
            for (int i=a+1; i<n; i++) {
                db[i]=t[i];
                sum+=db[i]*(1<<i);
                valt(i);
                if (db[i]) {
                    pos=i-1;
                    break;
                }
            }
            for (int i=pos; i>a; i--) {
                valt(i);
            }
            if (sum<b) {
                ans=-1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}