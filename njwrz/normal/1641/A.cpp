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
int n,x,a[200005];
map<int,int> mp;
void solve(){
	cin>>n>>x;
	mp.clear();
	FOR(i,1,n)cin>>a[i],mp[a[i]]++;
	sort(a+1,a+n+1);
	int cnt=0;
	FOR(i,1,n){
		if(!mp[a[i]])continue;
		if(mp[a[i]*x]){
			mp[a[i]*x]--;
			mp[a[i]]--;
		}else mp[a[i]]--,cnt++;
	}
	cout<<cnt<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve(); 
	RE 0;
}