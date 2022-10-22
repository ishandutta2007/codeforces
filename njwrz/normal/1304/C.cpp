#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,t[105],l[105],h[105];
void solve(){
    int x,y,z,cnt=0,m;
    cin>>n>>m;
    FOR(i,1,n){
        cin>>x>>y>>z;
        if(i==1||t[cnt]!=x){
            cnt++;
            t[cnt]=x;l[cnt]=y;h[cnt]=z;
        }else if(i>1){
            l[cnt]=max(l[cnt],y);
            h[cnt]=min(h[cnt],z);
        }
    }
    FOR(i,1,cnt){
        if(l[i]>h[i]){
            cout<<"NO\n";RE;
        }
    }
    int tl,tr,len;
    tl=tr=m;
    FOR(i,1,cnt){
        len=t[i]-t[i-1];
        tl-=len;
        tr+=len;
        tl=max(tl,l[i]);
        tr=min(tr,h[i]);
        if(tl>tr){
            cout<<"NO\n";RE;
        }
    }
    cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
    cin>>t;
    while(t--)solve();
	RE 0;
}