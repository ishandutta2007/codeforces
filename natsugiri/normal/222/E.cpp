#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;


typedef long long LL;
typedef vector<LL> Ary;
typedef vector<Ary> Mat;
const LL MOD=1000000007;

Mat mulModMat(const Mat&a, const Mat&b, LL mod) {
    int m=a.size(), n=a[0].size(), p=b[0].size();
    Mat r(m, Ary(p, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<p; k++) {
                r[i][k]=(r[i][k]+a[i][j]*b[j][k]);
                if (abs(r[i][k])>=mod) r[i][k]%=mod;
            }
        }
    }
    return r;
}

Mat powModMat(const Mat&a, LL b, const LL&mod) {
    if (b==1) return a;
    if (b%2) return mulModMat(a, powModMat(a, b-1, mod), mod);
    return powModMat(mulModMat(a, a, mod), b/2, mod);
}
Ary mulMatAry(const Mat&a, const Ary&x, LL mod) {
    int m=a.size(), n=a[0].size();
    Ary r(m, 0);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            r[i]=(r[i]+a[i][j]*x[j])%mod;
        }
    }
    return r;
}


LL n;
int m, k;
int nuc(char c) {
    if (isupper(c)) return c-'A'+26;
    return c-'a';
}
int main() {
    cin>>n>>m>>k;
    if (n==1) {
        cout<<m<<endl;
        return 0;
    }
    Mat A(m, Ary(m, 1));
    for (int i=0; i<k; i++) {
        char s[9];
        scanf("%s", s);
        int a, b;
        a=nuc(s[0]); b=nuc(s[1]);
        A[b][a]=0;
    }
    A=powModMat(A, n-1, MOD);
    Ary x(m, 1);
    x=mulMatAry(A, x, MOD);
    LL ans=0;
    for (int i=0; i<m; i++) ans=(ans+x[i])%MOD;
    cout<<ans<<endl;
    return 0;
}