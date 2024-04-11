#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<int> a,b;
int p[200006],mod=998244353;
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    FOR(i,1,200002)p[i]=p[i-1]*2%mod;
	int n,m;
	string x,y;
	cin>>n>>m>>x>>y;
	FOR(i,0,n-1){
		if(x[i]=='1')a.PB(n-i-1);
	}
	FOR(i,0,m-1){
		if(y[i]=='1')b.PB(m-i-1);
	}
	sort(ALL(a));
	sort(ALL(b));
	int ans=0;
	if(!a.size()){
		cout<<0;RE 0;
	}
	FOR(i,0,a.size()-1){
		ans=ans+(b.size()-(lower_bound(ALL(b),a[i])-b.begin()))*p[a[i]]%mod;
		ans=ans%mod;
	}
	cout<<ans;
	RE 0;
}