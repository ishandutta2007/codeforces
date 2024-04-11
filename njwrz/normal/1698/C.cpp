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
int n,a[200005],b[200005];
map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		mp.clear();
		FOR(i,1,n)cin>>a[i],mp[a[i]]=1;
		sort(a+1,a+n+1);
		if(!mp.count(a[1]+a[2]+a[3])){
			cout<<"NO\n";continue;
		}
		if(!mp.count(a[n]+a[n-1]+a[n-2])){
			cout<<"NO\n";continue;
		}
		int cnt=0,pos=0;
		FOR(i,1,n)if(a[i])b[++cnt]=a[i];else pos++;
		FOR(i,1,min(3ll,pos))b[++cnt]=0;
		bool ff=0;
		FOR(i,1,cnt)FOR(j,i+1,cnt)FOR(k,j+1,cnt){
			if(!mp.count(b[i]+b[j]+b[k])&&!ff){
				cout<<"NO\n";ff=1;
			}
		}
		if(!ff)cout<<"YES\n";
	}
	RE 0;
}