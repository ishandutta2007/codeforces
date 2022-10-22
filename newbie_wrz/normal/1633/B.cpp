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
int n;
string s;
int st[400005],ed[400005];
void solve(){
	cin>>s;
	n=s.size();
	FOR(i,0,n+n+1)st[i]=ed[i]=-1;
	int T=n;
	int ans=0;
	st[T]=ed[T]=0;
	FOR(i,1,n){
		if(s[i-1]=='0'){
			T++;
		}
		else {
			T--;
		}
		if(st[T]==-1)st[T]=i;
		ed[T]=i;
	}
	int maxi=-1e9;
	FOR(i,0,n+n){
	//	(j-i-T[j]+T[i])
		if(st[i]!=-1){
			gmax(ans,ed[i]-i+maxi);
			gmax(maxi,-st[i]+i);
		}
	}
	maxi=-1e9;
	for(int i=n+n;i>=0;i--){
		if(st[i]!=-1){
			gmax(ans,ed[i]+i+maxi);
			gmax(maxi,-st[i]-i);
		}
	}
	cout<<ans/2<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}