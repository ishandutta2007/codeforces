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
int num[10],len;
int check(int x){
	int re=x;
	rep(i,1,1<<len){
		int now=1;
		rep(j,0,len)if(i&(1<<j))now*=num[j];
		if(__builtin_popcount(i)&1)re-=x/now;
		else re+=x/now;
	}
	RE re;
}
void solve(){
	int s,n,t;
	cin>>s>>n>>t;
	len=0;
	int tn=n;
	for(int i=2;i*i<=tn;i++){
		if(n%i==0){
			num[len++]=i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n!=1)num[len++]=n;
	int cnt=s;
	rep(mask,1,1<<len){
		int now=1;
		rep(j,0,len)if(mask&(1<<j)){
			now*=num[j];
		}
		if(__builtin_popcount(mask)&1){
			cnt-=s/now;
		}else cnt+=s/now;
	}
	t+=cnt;
	int l=s+1,r=1e7,mid,ans;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)>=t){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
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