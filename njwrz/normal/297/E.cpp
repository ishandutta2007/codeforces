#include<bits/stdc++.h>
#define ll long long
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
P<int,int> p[100005];
struct Bit{
	int a[200005];
	void clear(){
		FILL(a,0);
	}
	void update(int x,int y){
		while(x<=2*n){
			a[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=a[x];
			x-=x&-x;
		}
		RE re;
	}
	void update(int l,int r,int x){
		update(l,x);
		update(r+1,-x);
	}
	int get(int l,int r){
		RE get(r)-get(l-1);
	}
}T; 
int p1[100005],p2[100005],sum1[200005],sum2[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
		sum1[p[i].F]=1;
		sum2[p[i].S]=1;
		if(p[i].F>p[i].S)swap(p[i].F,p[i].S);
	}
	FOR(i,1,n+n)sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
	sort(p+1,p+n+1);
	for(int i=n;i>=1;i--){
		p1[i]=T.get(p[i].F,p[i].S);
		T.update(p[i].S,1);
	}
	FOR(i,1,n){
		int now=sum2[p[i].S]-sum2[p[i].F-1]+sum1[p[i].S]-sum1[p[i].F-1]-p1[i]*2-2;
		p2[i]=n-1-now-p1[i];
	}
	ll ans=1ll*n*(n-1)*(n-2)/6;
	FOR(i,1,n)ans-=1ll*p1[i]*p2[i];
	ll sum=0;
	FOR(i,1,n)sum+=1ll*(p1[i]+p2[i])*(n-1-p1[i]-p2[i]);
	sum/=2;
	cout<<ans-sum;
	RE 0;
}