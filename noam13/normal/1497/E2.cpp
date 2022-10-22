#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e9, MOD = 1e9+7;

const int MAX = 1e7 + 10;
bool isp[MAX];
int conv[MAX];
int solve(){
    int n,k; cin>>n>>k;
    vi a(n);
    loop(i,0,n) cin>>a[i], a[i] = conv[a[i]];
    map<int, int> last;
    vi prev(n);
    loop(i,0,n){
        prev[i] = last[a[i]] - 1;
        last[a[i]] = i+1;
    }
    vvii dp(n+1, vii(k+1, {INF,INF}));
    loop(j,0,k+1) dp[0][j] = {1,0};
    loop(i,0,n){
        loop(j,0,k+1){
            if (dp[i][j].x==INF) continue;
            int v = dp[i][j].x, l = -dp[i][j].y;
            chkmin(dp[i+1][j], ii(v+1, -i));
            if (prev[i]<l) chkmin(dp[i+1][j], ii(v,-l));
            else if (j<k) chkmin(dp[i+1][j+1], ii(v, -l));
        }
    }
    int ans = dp[n][k].x;
    cout << ans << endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    fill(isp, isp+MAX, 1);
    fill(conv, conv+MAX, 1);
    conv[0] = 0;
    loop(i,2,MAX){
        if (!isp[i]) continue;
        for(int j = i; j<=MAX; j+=i){
            isp[j] = 0;
            if (j%(i*i) == 0){
                conv[j] = conv[j/(i*i)];
            }
            else conv[j] *= i;
        }
    }
    // loop(i,0,20) cout<<conv[i]<<" "; cout<<endl;
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ temp.cpp -D_GLIBCXX_DEBUG -o a & a
3
5 2
18 6 2 4 1
11 4
6 2 2 8 9 1 3 6 3 9 7
1 0
1



*/