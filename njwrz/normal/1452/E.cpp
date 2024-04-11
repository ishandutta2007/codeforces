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
int maxi[2005],n,m,k;
P<int,int> p[2005];
bool cmp(P<int,int> x,P<int,int> y){
    RE x.F+x.S<y.F+y.S;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    FOR(i,1,m){
    	cin>>p[i].F>>p[i].S;
	}
    sort(p+1,p+m+1,cmp);
    int t;
    FOR(i,1,n-k+1){
    	t=0;
        FOR(j,1,m){
            t+=max(0,min(i+k-1,p[j].S)-max(p[j].F,i)+1);
            gmax(maxi[j],t);
        }
    }
    int ans=0;
    FOR(i,1,n-k+1){
        t=0;
        for(int j=m+1;j>=1;j--){
            if(j<=m)t+=max(0,min(i+k-1,p[j].S)-max(p[j].F,i)+1);
            gmax(ans,t+maxi[j-1]);
        }
    }
    cout<<ans;
    RE 0;
}