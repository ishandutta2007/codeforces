#include <bits/stdc++.h>

using namespace std;
int n, k;
long long o[51];
bool v[51][51];
long long t[51];
long long r[62];
bool tart(long long a, long long b)
{
    if (b>a) {
        return 0;
    }
    while(a>0) {
        if (b%2>a%2) {
            return 0;
        }
        a/=2;
        b/=2;
    }
    return true;
}
bool ker(long long p)
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            v[j][i]=false;
            v[i][j]=false;
        }
    }
    for (int i=1; i<=n; i++) {
        if (tart(o[i], p)) {
            v[1][i]=true;
        }
    }
    for (int i=2; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            for (int c=j+1; c<=n; c++) {
                if (v[i-1][j] && tart(o[c]-o[j], p)) {
                    v[i][c]=true;
                }
            }
        }
    }
    return v[k][n];
}
int main()
{
    cin >> n >> k;
    r[0]=1;
    for (int i=1; i<=61; i++) {
        r[i]=r[i-1]*2;
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        o[i]=o[i-1]+t[i];
    }
    long long p=0;
    long long f=60;
    while(f>=0) {
        long long z=p+(long long)(r[f]);
        if (ker(z)) {
            p=z;
        }
        f--;
    }
    cout << p << endl;
    return 0;
}