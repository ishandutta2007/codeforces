#include <bits/stdc++.h>

using namespace std;

// matrix szorzas es hatvanyozas


long long mod=998244353, phi=402653184;

#define vvl vector<vector<long long>>
void print(vvl a) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) cout << a[i][j] << " ";
        cout << "\n";
    }
}
vvl mat_mul(vvl a, vvl b) {
    int n=a.size(), m=a[0].size(), k=b[0].size();
    vvl ans(n, vector<long long>(k, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int l=0; l<k; l++) {
                ans[i][l]=(ans[i][l]+a[i][j]*b[j][l])%(mod-1);
            }
        }
    }
    return ans;
}
vvl mat_pow(vvl a, long long po) {
    int n=a.size();
    vvl ans(n, vector<long long>(n, 0));
    for (int i=0; i<n; i++) {
        ans[i][i]=1;
    }
    while (po) {
        if (po%2) {
            ans=mat_mul(ans, a);
        }
        a=mat_mul(a, a);
        po/=2;
    }
    return ans;
}
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long po2(long long a, long long p, long long mod2) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod2;
        }
        a=a*a%mod2;
        p/=2;
    }
    return ans;
}




int n, k;
long long m, ert, gy=100000;
vvl x;

map<long long, int> hatv;

int main()
{
    cin >> n;
    x.resize(n);
    for (int i=0; i<n; i++) {
        x[i].resize(n);
    }
    for (int i=0; i<n-1; i++) {
        x[i][i+1]=1;
    }
    for (int j=n-1; j>=0; j--) {
        cin >> x[n-1][j];
    }
    cin >> k >> m;
    x=mat_pow(x, k-n);
    ert=x[n-1][n-1];




    // olyan a kell, ahol (a^ert==m)
    // 3^res=m -> a=3^(res/ert)

    long long hat=1, cnt=0;

    while (cnt<gy) {
        hatv[hat]=cnt;
        cnt++;
        hat=3*hat%mod;
    }
    long long hat2=1, cnt2=0, res=-1;
    while (true) {
        long long inv=m*po(hat2, mod-2)%mod;
        if (hatv.find(inv)!=hatv.end()) {
            res=cnt2+hatv[inv];
            break;
        }
        hat2=hat2*hat%mod;
        cnt2+=gy;
    }

    long long oszt=__gcd(ert, res);
    res/=oszt, ert/=oszt;
    long long b=res*po2(ert, phi-1, mod-1)%(mod-1);
    if (ert*b%(mod-1)==res) {
        cout << po(3, b) << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}