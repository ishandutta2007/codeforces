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
using namespace std;
int check(int x){
	int sum=0;
	FOR(i,0,9){
		int t=1;
		FOR(j,1,i)t*=10;
		int now=max(0ll,x-t+1);
		sum+=now*(now+1)/2;
	}
	RE sum;
}
int check2(int x){
	int sum=0;
	FOR(i,0,9){
		int t=1;
		FOR(j,1,i)t*=10;
		int now=max(0ll,x-t+1);
		sum+=now;
	}
	RE sum;
}
void solve(){
	int x;
	cin>>x;
	int l=1,r=2e9,mid,ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)>=x){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	int t=x-check(ans-1);
	l=1,r=ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check2(mid)>=t){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	t-=check2(ans-1);
//	cout<<t<<'\n';
	int a[20]={};
	int len=0;
	while(ans)a[++len]=ans%10,ans/=10;
	cout<<a[len-t+1]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}