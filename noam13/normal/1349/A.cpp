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
const int INF = 1e18, MOD = 1e9+7;


int gcd(int a, int b){
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a, a);
}
int lcm(int a, int b){
    return (a*b) / gcd(a,b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi pref(n); pref[n-1] = a[n-1];
    loopr(i,0,n-1) pref[i] = gcd(pref[i+1], a[i]);
    int ans = lcm(pref[n-1], a[n-2]);
    loopr(i,0,n-2) ans = gcd(ans, lcm(pref[i+1], a[i]));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
2
1 1

*/