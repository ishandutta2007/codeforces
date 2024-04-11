#include <bits/stdc++.h>

using namespace std;
long long mod=1000003;
long long t[12][12];
long long ans[12];
long long f[12];
long long oszt(long long a)
{
    long long p=1;
    long long h=a;
    long long x=1000001;
    while(x>0) {
        if (x%2!=0) {
            p*=h;
            p%=mod;
        }
        h*=h;
        h%=mod;
        x/=2;
    }
    return p;
}
int main()
{
    long long n=11;
    for (long long i=1; i<=n; i++) {
        cout.flush() << "? " << i << endl;
        long long x;
        cin >> x;
        t[i][n]=x;
        for (long long j=0; j<=n-1; j++) {
            long long c=1;
            for (long long k=1; k<=j; k++) {
                c*=i;
                c%=mod;
            }
            t[i][j]=c;
            //cout.flush() << t[i][j] << " ";
        }
        //cout << endl;
    }
    /*for (long long i=1; i<=n; i++) {
        for (long long j=0; j<=n; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/
    for (long long i=1; i<=n; i++) {
        for (long long j=0; j<=n-1; j++) {
            if (t[i][j]!=0) {
                long long x=oszt(t[i][j]);
                for (long long j=0; j<=n; j++) {
                    t[i][j]*=x;
                    t[i][j]%=mod;
                }
                for (long long k=i+1; k<=n; k++) {
                    for (long long l=0; l<=n; l++) {
                        if (l!=j) {
                            t[k][l]-=t[i][l]*(t[k][j]);
                            t[k][l]+=mod*mod;
                            t[k][l]%=mod;
                        }
                    }
                    t[k][j]=0;
                }
                break;
            }
        }
    }
    /*for (long long i=1; i<=n; i++) {
        for (long long j=0; j<=n; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }*/
    for (long long i=n; i>=1; i--) {
        for (long long j=n-1; j>=i; j--) {
            t[i][n]-=t[i][j]*ans[j];
            t[i][n]+=mod*mod;
            t[i][n]%=mod;
        }
        ans[i-1]=t[i][n];
    }
    for (int i=0; i<=n-1; i++) {
        //cout << ans[i] << " ";
    }
    for (long long i=0; i<mod; i++) {
        long long sum=0;
        long long x=1;
        for (long long j=0; j<n; j++) {
            sum+=x*ans[j];
            x*=i;
            sum%=mod;
            x%=mod;
        }
        if (sum==0) {
            cout.flush() << "! " << i << endl;
            return 0;
        }
    }
    cout.flush() << "! " << -1 << endl;
    return 0;
}