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
int a[200005],b[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,2*n)a[i]=b[i]=0;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	sort(b+1,b+n+1);reverse(b+1,b+n+1);
	int sum1=0,sum2=0,tl=n-n/4;
	FOR(i,1,tl)sum1+=a[i],sum2+=b[i];
	int ans=0,cnt=n%4,tr=tl;tr++;
	while(sum1<sum2){
		sum1+=100;
		if(cnt==3){
			sum1-=a[tl];tl--;
		}else sum2+=b[tr],tr++;
		cnt=(cnt+1)%4;
		ans++;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}