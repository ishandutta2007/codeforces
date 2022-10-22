#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD = 1e9+7;


int solve(){
    int n; cin>>n;
    vi a(n), b(n), c(n);
    loop(i,0,n) cin>>a[i]>>b[i];
    loop(i,0,n) c[i] = min(b[i], a[(i+1)%n]);
    int suma=0,sumc=0;
    loop(i,0,n) suma+=a[i], sumc+=c[i];
    int ans=INF;
    loop(i,0,n) chkmin(ans, suma-sumc+c[i]);
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
1
3
7 15
2 14
5 3

*/