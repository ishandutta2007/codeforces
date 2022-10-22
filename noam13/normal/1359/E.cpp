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
const int INF = 1e18, MOD = 998244353, MAX = 5e5 + 123;


int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b,p/2);
    return v*v%MOD  * (p%2?b:1)%MOD;
}
void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    vi fact(MAX,1);
    loop(i,2,MAX) fact[i] = fact[i-1] * i % MOD;
    int ans = 0;
    loop(i,1,n+1){
        int nn = n/i - 1;
        if (nn<k-1) break;
        int v = fact[nn] * pp(fact[k-1],MOD-2)%MOD;
        v = v * pp(fact[nn-(k-1)],MOD-2)%MOD;
        add(ans, v);
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
7 3

*/