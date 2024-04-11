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
        p*=10;
    }
    for (int i=1; i<c; i++) {
        long long s=i, sum=0;
        for (int j=1; j<=6; j++) {
            int x=s%10;
            s/=10;
            if (x%3==0) sum+=t[j]*x/3;
        }
        ert[i]=sum;
    }
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=0; i<=n; i++) maxi=max(maxi, regi[i]+ert[n-i]);
        cout << maxi << "\n";
    }
    return 0;
}