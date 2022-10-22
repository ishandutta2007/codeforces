#include <bits/stdc++.h>
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
const int INF = 1e9, MOD = 998244353;
 
const int N=15, M=1<<N;
int dp[N+1][M][N+1];
ii op[N+1][M][N+1];
int sum[M];
int n;

inline void add(vi &a, int s){
    loop(i,s,n) a[i]++;
}
int solve(){
    cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    int m = (1<<n);
    loop(s,0,m){
        sum[s] = 0;
        loop(i,0,n){
            if (s & (1<<i)) sum[s]+=a[i];
        }
    }
    loop(i,0,n+1) loop(s,0,m) loop(pos,0,n+1) dp[i][s][pos] = INF;
    dp[0][0][0] = 0; op[0][0][0] = {-1,-1};
    int fini = 0, fins = 0, finp = 0;
    loop(i,0,n){
        loop(s,0,m){
            loop(pos,0,n+1){
                int cur = dp[i][s][pos];
                if (cur==INF) continue;
                int left = (m-1) ^ s;
                for(int ps = left;ps;ps=(ps-1)&left){
                    if (ps >> pos == 0) continue;
                    if (sum[ps] <= dp[i][s][pos]) continue;
                    int npos = pos + __builtin_ctz(ps>>pos) + 1;
                    if (dp[i+1][s | ps][npos]>sum[ps]){
                        dp[i+1][s | ps][npos] = sum[ps];
                        op[i+1][s | ps][npos] = {ps, pos};
                    }
                }
            }
        }
    }
    loop(i,1,n+1){
        loop(pos,0,n+1){
            if (dp[i][m-1][pos]!=INF){
                fini = i, fins = m-1, finp = pos;
            }
        }
    }
    vi minus(n,0);
    vii ans;
    while(fini){
        ii oo = op[fini][fins][finp];
        int take = oo.x, pp = oo.y;
        loop(i,0,n){
            if (i==finp-1) continue;
            if (take & (1<<i)){
                ans.pb({finp-1 - minus[finp-1], i - minus[i]});
                add(minus, i);
            }
        }
        finp = pp;
        fins ^= take;
        fini--;
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.y+1<<" "<<p.x+1<<endl;
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
g++ f_forward.cpp -o a & a
4
8
2 1 3 5 1 2 4 5
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
2
3 3
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
 
 
 
 
*/