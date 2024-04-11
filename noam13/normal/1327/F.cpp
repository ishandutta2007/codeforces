#include <bits/stdc++.h>
//#define int int64_t
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int,int>
#define vvi vector<vi>
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
const int INF = 1e9, MOD=998244353;


int n,m;
vi dp;
vb ones;
int64_t solve(vii& yes, vii& no){
    sort(all(yes));
    loop(i,1,n+1) ones[i]=0;
    int last=-1;
    for(auto seg:yes){
        if (last<seg.x) last = seg.x;
        for(;last<=seg.y;last++) ones[last]=1;
    }
    for(auto &p:no) swap(p.x, p.y);
    sort(all(no));
    dp[0] = 1;
    int maxs = 0, sum=1, cur=0;
    loop(i,1,n+2){
        while(cur<no.size() && no[cur].x<i){
            while(maxs<no[cur].y){
                sum=(sum-dp[maxs++]+MOD)%MOD;
            }
            cur++;
        }
        if (ones[i]) {
            dp[i]=0; continue;
        }
        dp[i] = sum;
        sum=(sum+dp[i])%MOD;
    }
    return dp[n+1];
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>k>>m;
    vvii yes(k), no(k);
    dp = vi(n+2); ones = vb(n+1);
    loop(i,0,m){
        int l,r,x; cin>>l>>r>>x;
        loop(j,0,k) if (x&(1<<j)) yes[j].pb({l,r});
                    else no[j].pb({l,r});
    }
    int64_t ans=1;
    loop(i,0,k) ans = (ans * solve(yes[i], no[i])) %MOD;
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -o a & a
4 3 2
1 3 3
3 4 6


*/