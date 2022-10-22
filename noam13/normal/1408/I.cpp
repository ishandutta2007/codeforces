#include <bits/stdc++.h>
#define ll int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(),x.end()
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
using namespace std;
const int MOD = 998244353;

const int MAXN = (1<<17) +10;
ll poww(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD; 
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}
void add(int &a, int b){
    a = (a+b)%MOD;
}
const int MAXK = 17;
int n,k,c;

int C[60][60] = {0};

int32_t main(){
    ios_base::sync_with_stdio(false);
    loop(i,0,60){
        C[i][0] = C[i][i] = 1;
        loop(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
    }
    cin>>n>>k>>c;
    vvi nums(c+1); 
    int base = 0;
    loop(i,0,n){
        int x; cin>>x; base^=x;
        loop(j,0,c+1){
            int mask = (1<<j)-1;
            if ((x & mask) >= k){
                nums[j].pb(x&mask);
                break;
            }
        }
    }
    int sz = 1<<c;
    vvi dp(k+1, vi(sz,0));
    dp[0][0] = 1;
    loop(r,0,c+1){
        sort(all(nums[r]));
        for(auto x:nums[r]){
            loopr(i,0,k+1){
                loop(a,0,(1<<r)){
                    if (dp[i][a]==0) continue;
                    loop(j,1,k+1){
                        if (i+j>k) break;
                        add(dp[i+j][a ^ x ^ (x-j)], 1LL * dp[i][a] * C[i+j][j]%MOD);
                    }
                }
            }
        }
    }
    int inv = poww(poww(n, k), MOD-2);
    loop(i,0,sz){
        int v = 1LL * dp[k][i^base] * inv % MOD;
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ i.cpp -o a & a
2 2 2
3 2


2 2 3
3 4


4 1 4
9 10 11 4

4 1 4
1 2 3 4


1 1 1
1

*/