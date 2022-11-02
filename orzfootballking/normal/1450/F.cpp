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
int n,a[100005],p[100005],c[100005];
void solve(){
    cin>>n;
    int cnt=0;
    FOR(i,1,n)p[i]=0,c[i]=0;
    FOR(i,1,n){
        cin>>a[i];c[a[i]]++;
        if(i>1&&a[i]==a[i-1]){
            cnt++;p[a[i]]+=2;
        }
    }
    p[a[1]]++;p[a[n]]++;
    int maxi=0;
    FOR(i,1,n)gmax(maxi,c[i]);
    if(maxi>(n+1)/2){
        cout<<-1<<'\n';RE ;
    }
    maxi=0;
    FOR(i,1,n){
        gmax(maxi,p[i]);
    }
    cout<<cnt+max(0,maxi-cnt-2)<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    RE 0;
}