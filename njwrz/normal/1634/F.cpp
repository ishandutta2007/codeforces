#include<bits/stdc++.h>
#define int long long
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int f[300005],n,q,mod,a[300005],cnt=0;
void update(int x,int y){
	if(x<1||x>n)RE;
	if(a[x]!=0)cnt--;
	a[x]=(a[x]+y+mod)%mod;
	if(a[x]!=0)cnt++;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[1]=f[2]=1;
	cin>>n>>q>>mod;
	FOR(i,3,n)f[i]=(f[i-1]+f[i-2])%mod;
	FOR(i,1,n)cin>>a[i],a[i]%=mod;
	FOR(i,1,n){
		int x;
		cin>>x;
		a[i]=(a[i]-x%mod+mod)%mod;
	}
	for(int i=n;i>=1;i--){
		int t=(a[i]-a[i-1]-((i>1)?a[i-2]:0)+mod*2)%mod;
		cnt+=t!=0;
		a[i]=t;
	}
	FOR(_,1,q){
		char c;
		cin>>c;
		int m=1;
		if(c=='B')m=-1;
		int l,r;
		cin>>l>>r;
		update(l,m);
		update(r+1,-m*f[r-l+2]);
		update(r+2,-m*f[r-l+1]);
		if(cnt==0){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	RE 0;
}