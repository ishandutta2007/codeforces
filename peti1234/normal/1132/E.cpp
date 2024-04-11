#include <bits/stdc++.h>

using namespace std;
const long long c=200;
long long t[9], n, sum, maxi=10, f=200;
bool regi[212], uj[212], mar[9];
int main()
{
    cin >> n;
    for (long long i=1; i<=8; i++) {
        cin >> t[i];
        sum+=t[i]*i;
        if (t[i]) maxi=i;
    }
    regi[0]=1;
    for (long long i=1; i<=maxi; i++) {
        for (long long j=1; j<=min(f, t[i]); j++) {
            for (long long k=0; k<c; k++) {
                if (regi[k]) {
                    uj[k]=1;
                    uj[k+i]=1;
                }
            }
            for (long long k=0; k<c; k++) {
                regi[k]=uj[k];
                uj[k]=0;
            }
        }
    }
    for (long long i=0; i<c; i++) {
        if (regi[i]) {
            mar[i%maxi]=1;
        }
    }
    if (sum<=n) {
        cout << sum << "\n";
        return 0;
    }
    if (n<c) {
        long long ans=0;
        for (long long i=0; i<=n; i++) {
            if (regi[i]) ans=i;
        }
        cout << ans << "\n";
        return 0;
    }
    if (sum-n<100) {
        for (long long i=sum-n; i<=c; i++) {
            if (regi[i]) {
                cout << sum-i << "\n";
                return 0;
            }
        }
    }
    long long p=n%maxi;
    for (long long i=p; i>=0; i--) {
        if (mar[i]) {
            cout << n-p+i << "\n";
            return 0;
        }
    }
    return 0;
}
/*
11994176272990019
0 6395394930893349 0 0 0 0 0 0
*/