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
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 998244353;
const int MAX = 4e5 + 123;

int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b, p/2);
    return (v*v)%MOD * (p%2?b:1) %MOD;
}
vi fact(MAX,1);
vi invfact(MAX,1);
void precalc(){
    loop(i,1,MAX) fact[i] = fact[i-1] * i % MOD;
    loop(i,0,MAX) invfact[i] = pp(fact[i], MOD - 2);
}
int choose(int a, int b){
    int ans = fact[a] * invfact[b] % MOD;
    return ans * invfact[a-b] %MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    if (k>=n) return cout<<0<<endl,0;
    precalc();
    if (k==0) return cout<<fact[n]<<endl,0;
    int ans = 0;
    int b = n-k;
    loop(i,0,b+1){
        int v = choose(b,i) * pp(b-i, n);
        ans = (ans + (i%2?-v:v) + MOD)%MOD;
    }
    //cout<<n<<" "<<b<<" "<<choose(n,b)<<endl;
    ans = ans*2 * choose(n,b) %MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
3 2


*/