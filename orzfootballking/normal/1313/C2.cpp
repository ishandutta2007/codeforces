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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int l[500005],r[500005],a[500005],n;
stack<int> s;
int lp[500005],rp[500005];
int sc[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n+1){
		while(!s.empty()&&a[s.top()]>a[i]){
			r[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())s.pop();
	for(int i=n;i>=0;i--){
		while(!s.empty()&&a[s.top()]>a[i]){
			l[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	int t;
	FOR(i,1,n){
		t=l[i];
		lp[i]=lp[t]+(i-t)*a[i];
	}
	for(int i=n;i>=1;i--){
		t=r[i];
		rp[i]=rp[t]+(t-i)*a[i];
	}
	int maxi=0,ans;
	FOR(i,1,n){
		if(lp[i]+rp[i]-a[i]>maxi){
			maxi=lp[i]+rp[i]-a[i];
			ans=i;
		}
	}
	sc[ans]=a[ans];
	for(int i=ans-1;i>=1;i--)sc[i]=min(sc[i+1],a[i]);
	FOR(i,ans+1,n)sc[i]=min(sc[i-1],a[i]);
	FOR(i,1,n)cout<<sc[i]<<' ';
	RE 0;
}