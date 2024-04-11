#include<bits/stdc++.h>
#define int long long

using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

// using namespace std;
const int maxn=200007;
const int mod=998244353;
int n;
int x[maxn],y[maxn],w[maxn];
int dp[maxn];
int C[maxn][2];

int lowbit(int u){
    return u&(-u);
}

void update(int u,int w,int k){
    for (int i=u;i<=n;i+=lowbit(i)) C[i][k]=(C[i][k]+w)%mod;
}

int query(int u,int k){
    int ans=0;
    for (int i=u;i>0;i-=lowbit(i)) ans=(ans+C[i][k])%mod;
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep1(i,n) cin>>x[i]>>y[i]>>w[i];
    int ans=0;
    rep1(i,n) {
        int lb=lower_bound(x+1,x+i+1,y[i])-x-1;
        if (lb!=i-1) {
            dp[i]=(-y[i]+x[lb]+query(i-1,0)-query(lb,0)+2*(x[i]-x[i-1])+2*mod)%mod;
        }
        else{
            dp[i]=(2*x[i]-y[i]-x[i-1])%mod;
        }
        update(i,dp[i],0);
        update(i,y[i],1);
        if (w[i]) ans=(ans+dp[i])%mod;
        else ans=(ans+x[i]-x[i-1])%mod;
    }
    cout<<(ans+1)%mod<<"\n";
    return 0;
}