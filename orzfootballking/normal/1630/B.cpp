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
int n,k,a[200005];
int sum[200005];
bool f[200005];
void solve(){
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i],sum[i]=0;
	FOR(i,1,n)sum[a[i]]++;
	int l=0,now=0,tl=-1,tr=-1,mini=1e9;
	FOR(i,1,n){
		now+=sum[i];
		while((now-sum[l+1])*2>=n+k)l++,now-=sum[l];
		if(i-(l+1)<mini&&now*2>=n+k){
			mini=i-(l+1);
			tl=l+1;tr=i;
		}
	}
	cout<<tl<<' '<<tr<<'\n';
	if(k==1){
		cout<<1<<' '<<n<<'\n';RE ;
	}
	int lst=0,s=0;
	int cnt=0;
	FOR(i,1,n){
		if(a[i]>=tl&&a[i]<=tr){
			s--;
		}else s++;
		if(s<0){
			cnt++;
			cout<<lst+1<<' '<<i<<'\n';
			s=0;
			lst=i;
			if(cnt==k-1){
				cout<<i+1<<' '<<n<<'\n';
				break;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}