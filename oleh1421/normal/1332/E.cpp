//#pragma GCC optimize ("trapv")
//#pragma GCC opitmize ("unroll-loops")

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll mod=998244353ll;
struct matrix{
    ll a[2][2];
};
matrix mult(matrix x,matrix y){
    matrix res;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            res.a[i][j]=0;
            for (int t=0;t<2;t++){
                res.a[i][j]+=x.a[i][t]*y.a[t][j];
                res.a[i][j]%=mod;
            }
        }
    }
    return res;
}
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
matrix binpow_matrix(matrix a,ll b){
    if (b==1) return a;
    if (b%2) return mult(a,binpow_matrix(a,b-1));
    else return binpow_matrix(mult(a,a),b/2ll);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,L,R;cin>>n>>m>>L>>R;
    if (n%2 && m%2){
        cout<<binpow(R-L+1ll,n*m)<<endl;
        return 0;
    }
    ll cnt0=(R/2ll - (L-1)/2ll);
    ll cnt1=((R+1ll)/2ll-L/2ll);
    matrix A;
    A.a[0][0]=A.a[1][1]=cnt0;
    A.a[1][0]=A.a[0][1]=cnt1;
    matrix B;
    B.a[0][0]=cnt0;
    B.a[0][1]=cnt1;
    B.a[1][0]=B.a[1][1]=0ll;
    B=mult(B,binpow_matrix(A,n*m-1ll));
    cout<<B.a[0][0];
    return 0;
}
/*
0 0
0 0
*/