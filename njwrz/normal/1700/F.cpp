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
int a[2][200005],b[2][200005],dp[2][200005]; 
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int cnt=0;
	rep(i,0,2)FOR(j,1,n)cin>>a[i][j],cnt+=a[i][j];
	rep(i,0,2)FOR(j,1,n)cin>>b[i][j],cnt-=b[i][j];
	if(cnt){
		cout<<-1;RE 0;
	}
	int cnt1=0,cnt2=0,ans=0;
	FOR(i,1,n){
		ans+=abs(cnt1)+abs(cnt2);
		if(a[0][i]>b[0][i]){
			if(cnt1<0)cnt1++;
			else if(cnt2<0&&(a[1][i]<=b[1][i]||cnt2<-1))cnt2++,ans++;
			else cnt1++;
		}else if(a[0][i]<b[0][i]){
			if(cnt1>0)cnt1--;
			else if(cnt2>0&&(a[1][i]>=b[1][i]||cnt2>1))cnt2--,ans++;
			else cnt1--;
		}
		if(a[1][i]>b[1][i]){
			if(cnt2<0)cnt2++;
			else if(cnt1<0)cnt1++,ans++;
			else cnt2++;
		}else if(a[1][i]<b[1][i]){
			if(cnt2>0)cnt2--;
			else if(cnt1>0)cnt1--,ans++;
			else cnt2--;
		}
//		cout<<ans<<'\n';
	}
	cout<<ans;
	RE 0;
}