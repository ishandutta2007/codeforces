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

int solve(){
    int n; cin>>n;
    vi a(n); 
    loop(i,0,n) cin>>a[i], a[i] = (a[i]%n + n)%n;
    vb taken(n,0);
    loop(i,0,2*n){
        int p = i + a[i%n] - n;
        if (p>=0 && p<n) taken[p] = 1;
    }
    bool emp = 0;
    loop(i,0,n) if (!taken[i]) emp = 1;
    cout<<(emp?"NO":"YES")<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
6
1
14
2
1 -1
4
5 5 5 1
3
3 2 1
2
0 1
5
-239 -2 -100 -3 -11

*/