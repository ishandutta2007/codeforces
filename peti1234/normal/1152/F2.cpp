#include <bits/stdc++.h>

using namespace std;
#define vvl vector<vector<long long>>
long long n, m, po, k, mod=1e9+7;
vvl st, valt;
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

vvl matpow(vvl a, int po) {
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
int main()
{
    cin >> n >> k >> m;
    po=(1<<m);
    st.resize(1);
    int h=(k+1)*po;
    st[0].resize(h);
    st[0][0]=1;
    valt.resize(h);
    for (int i=0; i<h; i++) {
        valt[i].resize(h);
    }
    for (int k1=0; k1<=k; k1++) {
        for (int mask1=0; mask1<po; mask1++) {
            for (int k2=0; k2<=k; k2++) {
                for (int mask2=0;mask2<po; mask2++) {
                    int p1=k1*po+mask1, p2=k2*po+mask2;
                    if (k1==k2 && 2*mask1%po==mask2) {
                        valt[p1][p2]=1;
                    }
                    if (k1+1==k2 && 2*mask1%po+1==mask2) {
                        valt[p1][p2]=__builtin_popcount(mask1)+1;
                    }
                    if (valt[p1][p2]) {
                        //cout << "fontos " << k1 << " " << mask1 << " " << k2 << " " << mask2 << "\n" << p1 << " " << p2 << " " << valt[p1][p2] << "\n";
                    }
                }
            }
        }
    }
    valt=matpow(valt, n);
    /*cout << "hatvany\n";
    for (int i=0; i<h; i++) {
        for (int j=0; j<h; j++) {
            cout << valt[i][j] << " ";
        }
        cout << "\n";
    }*/
    vvl ans=matmul(st, valt);
    /*for (int i=0; i<h; i++) {
        cout << ans[0][i] << " ";
        if (i%po==po-1) {
            cout << "\n";
        }
    }*/
    long long res=0;
    for (int i=h-po; i<h; i++) {
        res+=ans[0][i];
    }
    cout << res%mod << "\n";
    return 0;
}
/*
3 3 1
*/