#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,sum,ans=0,t;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	while(1){
		sum=t=0;
		FOR(i,1,n)
			if(m>=a[i]){
				sum+=a[i];t++;ans++;
				m-=a[i];
			}
		if(!t)break;
		ans=ans+m/sum*t;
		m=m%sum;
	}
	cout<<ans;
	RE 0;
}