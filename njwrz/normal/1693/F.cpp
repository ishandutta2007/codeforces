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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
char c[200005];
int n;
int s[200005],lst[400005],cnt[200005];
void solve(){
	cin>>n;
	int cnt0=0,cnt1=0;
	FOR(i,1,n){
		cin>>c[i];
		if(c[i]=='0')cnt0++;else cnt1++;
	}
	if(!cnt0||!cnt1){
		cout<<0<<'\n';RE ;
	}
	if(cnt0<cnt1){
		reverse(c+1,c+n+1);
		FOR(i,1,n)c[i]^=1;
	}
	FOR(i,0,n+n)lst[i]=0;
	FOR(i,1,n){
		if(c[i]=='0')s[i]=s[i-1]+1;else s[i]=s[i-1]-1;
		cnt[i]=cnt[i-1]+(c[i]=='1');
		lst[s[i]]=i;
	}
	int it=0;
	while(c[it+1]=='0')it++;
	while(it<n&&c[it+1]=='1')it++;
	int ans=0;
	while(it<n){
		int pos=it-cnt[it];
		if(pos>=s[n]){
			ans++;break;
		}
		int to=lst[pos];
		ans++;
		it=to;
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