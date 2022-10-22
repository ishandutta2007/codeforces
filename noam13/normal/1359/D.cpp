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


int n;
int solve(vi& a, int c){
    int ans = 0, cur = 0;
    loop(i,0,n){
        if (a[i]>c) cur = 0;
        else{
            cur+=a[i];
            chkmax(ans, cur);
            chkmax(cur, int(0));
        }
    }
    //cout<<"C: "<<ans<<endl;
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int ans = 0;
    loop(c,0,31) chkmax(ans, (solve(a,c)-c));
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
5
5 -2 10 -1 4

*/