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
int n,a[400005];
V<P<int,int> > p;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	k=k*8/n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int len=1,last=a[1];
	FOR(i,2,n){
		if(a[i]!=last){
			p.PB(MP(last,len));
			len=1;last=a[i];
		}else len++;
	}
	p.PB(MP(last,len));
	int t=1;
	FOR(i,1,k){
		t*=2;
		if(t>=p.size()){
			cout<<0;RE 0;
		}
	}
	k=t;
	int sum=0;
	rep(i,0,k)sum+=p[i].S;
	int ans=sum;
	rep(i,1,p.size()-k+1){
		sum-=p[i-1].S;
		sum+=p[i+k-1].S;
		ans=max(ans,sum);
	}
	cout<<n-ans;
	RE 0;
}