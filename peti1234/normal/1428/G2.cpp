#include <bits/stdc++.h>

using namespace std;
const long long c=1000002, f=-1e18;
long long t[12], regi[c], uj[c], ert[c], w, k, n, maxi, p=1;
void add(long long a, long long b) {
    for (int i=0; i<c; i++) {
        uj[i]=regi[i];
        if (i>=a) uj[i]=max(uj[i], regi[i-a]+b);
    }
    for (int i=0; i<c; i++) regi[i]=uj[i];
}
int main()
{
    cin >> k, k--;
    for (int i=1; i<c; i++) regi[i]=f;
    for (int i=1; i<=6; i++) {
        cin >> t[i];
        long long s=3*k, po=1;
        while(s>=po) {
            add(po*p*3, po*t[i]);
            s-=po, po*=2;
        }
        if (s) add(s*p*3, s*t[i]);
        vector<pair<long long, long long> > sz;
        for (int j=0; j<10; j++) {
            s=0;
            if (j%3==0) s=j/3*t[i];
            sz.push_back({j*p, s});
        }
        for (int i=c-1; i; i--) {
            uj[i]=regi[i];
            for (int j=0; j<10; j++) {
                long long fi=sz[j].first, se=sz[j].second;
                if (i>=fi) uj[i]=max(uj[i], regi[i-fi]+se);
            }
        }
        for (int i=0; i<c; i++) regi[i]=uj[i];
        p*=10;
    }
    cin >> w;
    while(w--) {
        cin >> n;
        cout << uj[n] << "\n";
    }
    return 0;
}