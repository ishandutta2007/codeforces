#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;--i)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 998244353;

void add(int &a, int b){
    a = (a+b) % MOD;
}
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return (v*v)%MOD * (p%2?b:1) %MOD;
}
int n;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi fact(n+1,1), invf(n+1);
    loop(i,2,n+1) fact[i] = fact[i-1] * i % MOD;
    loop(i,0,n+1) invf[i] = pp(fact[i], MOD-2);
    vvi c(n+1, vi(n+1,0));
    c[1][0] = 1;
    loop(i,2,n+1){
        loop(j,0,i){
            c[i][j] = (j+1) * c[i-1][j] % MOD;
            if (j) add(c[i][j], (i-j)*c[i-1][j-1]);
        }
    }
    //cout<<"C: "<<c[2][1]<<" "<<fact[n]<<" "<<invf[n]<<endl;
    loop(i,1,n+1){
        int ans = 0;
        loop(j,i,n+1) add(ans, c[j][i-1] * fact[n] % MOD * invf[j]);
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
2


*/