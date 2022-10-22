#include <bits/stdc++.h>
//#define int int64_t
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
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e9;

int solve(){
    int n,k; cin>>n>>k;
    vector<pair<ii,int>> arr(n); loop(i,0,n) cin>>arr[i].x.y>>arr[i].x.x, arr[i].y=i+1;
    sort(all(arr));
    vi a(n), b(n);
    loop(i,0,n) a[i]=arr[i].x.y, b[i]=arr[i].x.x;
    vvi dp(n+1, vi(k+1, -INF));
    vvb op(n+1, vb(k+1,0));
    dp[0][0] = 0;
    loop(i,0,n){
        dp[i+1][0] = dp[i][0] + (k-1)*b[i];
        loop(j,1,k+1){
            int v1 = dp[i][j] + (k-1)*b[i], v2 = dp[i][j-1] + (j-1)*b[i] + a[i];
            if (v2>v1) op[i+1][j] = 1;
            dp[i+1][j] = max(v1,v2);
        }
    }
    int curj = k;
    vi maj, bon;
    for(int i=n;i;i--){
        int oo = op[i][curj];
        if (oo){
            maj.pb(i-1);
            curj--;
        }
        else{
            bon.pb(i-1);
        }
    }
    cout<<n+n-k<<endl;
    loopr(i,1,k) cout<<arr[maj[i]].y<<" ";
    for(auto i:bon) cout<<arr[i].y<<" "<<-arr[i].y<<" ";
    cout<<arr[maj[0]].y<<endl;
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
g++ SummoningMinions.cpp -o a & a
3
5 2
5 3
7 0
5 0
4 0
10 0
2 1
10 100
50 10
5 5
1 5
2 4
3 3
4 2
5 1


*/