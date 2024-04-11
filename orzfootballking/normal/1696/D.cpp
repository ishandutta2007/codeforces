#include<bits/stdc++.h>
#define int long long
#define lb long double
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
int nxtmi[250005],nxtmx[250005];
int dp[250005][2],n,a[250005],tomi[250005],tomx[250005],l2[250005];
P<int,int> mi[250005][20],mx[250005][20];
int getmi(int l,int r){
	int t=l2[r-l+1];
	RE min(mi[l][t],mi[r-(1<<t)+1][t]).S;
}
int getmx(int l,int r){
	int t=l2[r-l+1];
	RE max(mx[l][t],mx[r-(1<<t)+1][t]).S;
}
void solve(){
	cin>>n;
	FOR(i,2,n)l2[i]=l2[i/2]+1;
	FOR(i,1,n)cin>>a[i],nxtmi[i]=nxtmx[i]=0;
	stack<int> s;
	FOR(i,1,n){
		while(!s.empty()&&a[s.top()]>a[i])nxtmi[s.top()]=i,s.pop();
		s.emplace(i);
	}
	while(!s.empty())s.pop();
	FOR(i,1,n){
		while(!s.empty()&&a[s.top()]<a[i])nxtmx[s.top()]=i,s.pop();
		s.emplace(i);
	}
	FOR(i,1,n){
		mi[i][0]=mx[i][0]=MP(a[i],i);
	}
	rep(j,1,19){
		FOR(i,1,n-(1<<j)+1){
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
	FOR(i,1,n){
		if(!nxtmi[i])nxtmi[i]=n+1;
		if(!nxtmx[i])nxtmx[i]=n+1;
		tomi[i]=getmi(i,nxtmx[i]-1);
		tomx[i]=getmx(i,nxtmi[i]-1);
//		cout<<tomi[i]<<' '<<tomx[i]<<'\n';
	}
	int now=1,ans=0,cnt=0,tap=0,lst=-1;
	while(now<n){
		if(tap){
			now=tomx[now];
		}
		else now=tomi[now];
		if(now==lst){
			cnt=1e18;break;
		}
		lst=now;tap^=1;
		cnt++;
	}
	ans=cnt;
	cnt=0;
	now=1;
	tap=1;lst=-1;
	while(now<n){
		if(tap){
			now=tomx[now];
		}
		else now=tomi[now];
		if(now==lst){
			cnt=1e18;break;
		}
		lst=now;tap^=1;
		cnt++;
	}
	gmin(ans,cnt);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}