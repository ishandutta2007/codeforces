#include <bits/stdc++.h>

using namespace std;
#define vvl vector<vector<long long>>
long long mod=1e9+6, mod2=1e9+7;
vvl matmul(vvl a, vvl b) {
    int n=a.size(), m=a[0].size(), k=b[0].size();
    vvl ans;
    ans.resize(n);
    for (int i=0; i<n; i++) {
        ans[i].resize(m);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int l=0; l<k; l++) {
                ans[i][l]=(ans[i][l]+a[i][j]*b[j][l])%mod;
            }
        }
    }
    return ans;
}
vvl matpow(vvl a, long long po) {
    int n=a.size();
    vvl ans;
    ans.resize(n);
    for (int i=0; i<n; i++) {
        ans[i].resize(n);
        for (int j=0; j<n; j++) {
            ans[i][j]=(i==j);
        }
    }
    while (po) {
        if (po%2) {
            ans=matmul(ans, a);
        }
        a=matmul(a, a);
        po/=2;
    }
    return ans;
}
long long po(long long a, long long b) {
    long long ans=1;
    while (b) {
        if (b%2) {
            ans*=a, ans%=mod2;
        }
        a*=a, a%=mod2;
        b/=2;
    }
    return ans;
}
long long n, f[3], c, ans=1;
vvl sor1, sor2, mat1, mat2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> f[0] >> f[1] >> f[2] >> c;
    sor1.resize(1), sor2.resize(1), mat1.resize(3), mat2.resize(5);
    for (int i=0; i<3; i++) {
        mat1[i].resize(3);
    }
    mat1[0][2]=1;
    mat1[1][0]=1;
    mat1[1][2]=1;
    mat1[2][1]=1;
    mat1[2][2]=1;
    for (int i=0; i<3; i++) {
        sor1[0]={0, 0, 0};
        sor1[0][i]=1;
        long long hat=matmul(sor1, matpow(mat1, n-3))[0].back();
        ans=ans*po(f[i], hat)%mod2;
    }
    for (int i=0; i<5; i++) {
        mat2[i].resize(5);
    }
    mat2[0][0]=1;
    mat2[0][4]=1;
    mat2[1][4]=-1;
    mat2[2][1]=1;
    mat2[3][2]=1;
    mat2[4][3]=1;
    mat2[4][4]=2;
    sor2[0]={2, 0, 0, 0, 0};
    long long hat=matmul(sor2, matpow(mat2, n-3))[0].back();
    ans=ans*po(c, hat)%mod2;

    cout << ans << "\n";
    return 0;
}