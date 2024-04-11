/*


DP





ll int
 dp 









*/
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n;
int a[300005],log_2[300005],mini[300005][19],cnt[300005];
int get(int x,int y){
    int t=log_2[y-x+1];
    RE min(mini[x][t],mini[y-(1<<t)+1][t]);
}
bool check(int x){
    FOR(i,1,n)cnt[i]=0;
    FOR(i,1,n-x+1){
        cnt[get(i,i+x-1)]++;
    }
    FOR(i,1,n-x+1){
        if(cnt[i]!=1){
            RE 0;
        }
    }
    RE 1;
}
void solve(){
    cin>>n;
    FOR(i,1,n)cin>>a[i],mini[i][0]=a[i];
    FOR(i,1,18){
        FOR(j,1,n){
            if(j+(1<<i)-1<=n)mini[j][i]=min(mini[j][i-1],mini[j+(1<<(i-1))][i-1]);
        }
    }
    int l=2,r=n,mid,ans=n+1;
    while(r>=l){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;ans=mid;
        }else l=mid+1;
    }
    if(check(1)){
        cout<<1;
    }else cout<<0;
    rep(i,2,ans){
        cout<<0;
    }
    FOR(i,ans,n){
        cout<<1;
    }
    cout<<'\n';
}
signed main(){
    FOR(i,2,300000)log_2[i]=log_2[i/2]+1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    RE 0;
}