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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)a[i]=i;
	int ans=0;
	FOR(i,1,n)ans+=(i-1)/2;
	if(ans<m){
		cout<<-1;RE 0;
	}
	m=ans-m;
	int maxx=1e9,t;
	for(int i=n;i>=1;i--){
		t=(i-1)/2;
		if(m>t){
			m-=t;
			a[i]=maxx;
			maxx-=10000;
		}else{
			while(m){
				if(a[i]&1)m--;
				a[i]++;
			}
		}
	}
	FOR(i,1,n)cout<<a[i]<<' ';
	RE 0;
}