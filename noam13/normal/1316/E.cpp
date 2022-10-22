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
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18;

int n,p,k;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>p>>k;
    vii arr(n);
    loop(i,0,n) {
        cin>>arr[i].x; arr[i].y=i;
    }
    sort(all(arr)); reverse(all(arr));
    //loop(i,0,n) cout<<arr[i].y<<" ";
    vvi tmps(n,vi(p));
    loop(i,0,n) loop(l,0,p) cin>>tmps[i][l];
    vi a(n);
    vvi s(n, vi(p));
    loop(i,0,n){
        int j = arr[i].y;
        a[i] = arr[i].x;
        s[i] = tmps[j];
    }
    int R = 1<<p;
    vvi dp(n+1,vi(R,-INF));
    dp[0][0] = 0;
    loop(i,0,n){
        loop(r,0,R){
            chkmax(dp[i+1][r], dp[i][r]);
            int cnt = 0;
            loop(j,0,p) {
                int cur = (r>>j)&1;
                if (cur==0) chkmax(dp[i+1][r|(1<<j)], dp[i][r] + s[i][j]);
                cnt+=cur;
            }
            if (i-cnt<k) chkmax(dp[i+1][r], dp[i][r] + a[i]);
        }
    }
    cout<<dp[n][R-1]<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
4 1 2
1 16 10 3
18
19
13
15

*/