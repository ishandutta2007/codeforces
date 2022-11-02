#pragma GCC optimize("Ofast")
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
map<int,int> m;
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int sum=0,ans=0,l=-1;
	m[0]=0;
	FOR(i,1,n){
		sum+=a[i];
		if(m.count(sum))gmax(l,m[sum]);
		ans+=i-l-1;
		m[sum]=i;
	}
	cout<<ans;
	RE 0;
}