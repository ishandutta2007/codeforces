#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-6
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define two(x) (1<<(x))

int x[33],y[33],n,a,b,dis[33][33],dp[1<<24];
vector<pair<int,int> > ans;

int lastbit(int x) {
    for(int i=n-1;i>=0;i--) if(x&(1<<i)) return i;
}


int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>x[0]>>y[0]>>n;
    x[n]=x[0];y[n]=y[0];
    For(i,0,n) cin>>x[i]>>y[i];
    For(i,0,n+1) For(j,0,n+1) dis[i][j]=dis[j][i]=(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
    For(mask,1,1<<24) {
        a = lastbit(mask);
        int bef = mask^(1<<a);
        dp[mask] = dp[bef] + dis[n][a]*2;
        For(i,0,a) if(bef&(1<<i)) dp[mask] = min(dp[mask], dp[bef^(1<<i)] + dis[n][i] + dis[i][a] + dis[a][n]);
    }
    int ini = (1<<n)-1;
    cout<<dp[ini]<<endl;
    while(ini) {
        a = lastbit(ini);
        b = -1;
        int tmp = ini;
        ini^=(1<<a);
        For(i,0,a) if(ini&(1<<i)) if(dp[tmp]==dp[ini^(1<<i)]+dis[n][a]+dis[a][i]+dis[i][n]) b=i;
        if(b==-1) cout<<0<<' '<<a+1<<' ';
        else {
            cout<<0<<' '<<a+1<<' '<<b+1<<' ';
            ini^=(1<<b);
        }
    }
    cout<<0;
}