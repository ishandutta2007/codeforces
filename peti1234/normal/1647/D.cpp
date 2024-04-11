#include <bits/stdc++.h>

using namespace std;
long long p=1e9, w, x, d;
map<int, int> hv;
bool pr(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i==0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    for (long long po=2; po<=30; po++) {
        for (int i=2; i<=p; i++) {
            long long ert=1;
            for (int j=1; j<=po; j++) {
                ert=ert*i;
            }
            if (ert>p) break;
            hv[ert]=po;
        }
    }
    cin >> w;
    while (w--) {
        cin >> x >> d;
        if (x%(d*d)) {
            cout << "NO\n";
            continue;
        }
        long long s=(hv.find(d)==hv.end() ? 1 : hv[d]);
        x/=d*d;
        if (s==1) {
            bool jo=1;
            for (int i=2; i*i<=d; i++) {
                if (d%i==0 && d%(i*i)!=0) {
                    jo=0;
               }
            }
            //cout << "vege " << jo << "\n";
            if (jo) {
                while (x%d==0) {
                    x/=d;
                }
            }
            //cout << "ertek " << x << "\n";
        }
        if (s==2) {
            int koz=sqrt(d);
            if (pr(koz) && x%(d*koz)==0) {
                x/=d;
            }
        }
        bool jo=0;
        for (int i=2; i*i<=x; i++) {
            if (x%i==0) {
                jo=1;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*
1
675225424 2
*/