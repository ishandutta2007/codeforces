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
void sub(int &a, int b){
    a = (a-b)%MOD;
    if (a<0) a+=MOD;
}
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return (v*v)%MOD * (p%2?b:1) %MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    int m = 0;
    vi a(n); loop(i,0,n) cin>>a[i], m+=a[i];
    vi f(m+1,0);
    loop(i,0,m){
        int v = (i * f[i] + m)% MOD * (n-1) % MOD;
        f[i+1] = v * pp(m-i,MOD-2) % MOD;
    }
    loop(i,1,m+1) add(f[i], f[i-1]);
    int ans = f[m];
    loop(i,0,n) sub(ans, f[a[i]]);
    ans = ans * pp(n,MOD-2) % MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d2.cpp -o a & a
2
1 1


*/