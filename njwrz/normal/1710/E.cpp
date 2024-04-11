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
int n,m,a[200005],b[200005];
int ta,tb;
int da[200005],db[200005];
bool check(int x){
	da[0]=m;
	FOR(i,1,n){
		da[i]=da[i-1];
		while(da[i]&&a[i]+b[da[i]]>x)da[i]--;
	}
	db[0]=n;
	FOR(i,1,m){
		db[i]=db[i-1];
		while(db[i]&&b[i]+a[db[i]]>x)db[i]--;
	}
//	FOR(i,1,n){
//		FOR(j,1,m)cout<<a[i]+b[j]<<' ';
//		cout<<'\n';
//	}
	int tj=0;
	int maxi=0,sum=0;
	FOR(i,1,n)sum+=m-da[i];
	maxi=sum;
	FOR(i,1,n){
		sum-=m-max(tj,da[i]);
		sum+=min(tj,da[i]);
		while(tj<m&&-n+max(i,db[tj+1])+min(i,db[tj+1])>0)sum+=-n+max(i,db[tj+1])+min(i,db[tj+1]),tj++;
		gmax(maxi,sum);
	}
	sum=0;tj=0;
	FOR(i,1,n)sum+=m-da[i];
	FOR(i,1,n){
		sum-=m-max(tj,da[i]);
		sum+=min(tj,da[i]);
		while(tj<m&&-n+max(i,db[tj+1])+min(i,db[tj+1])>=0)sum+=-n+max(i,db[tj+1])+min(i,db[tj+1]),tj++;
		if(sum==maxi){
			if(i>=ta||tj>=tb)RE 1;
		}
	}
	RE 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m)cin>>b[i];
	ta=a[1],tb=b[1];
	int l=2,r=ta+tb-1,ans=ta+tb,mid;
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	FOR(i,1,n)if(a[i]==ta){
		ta=i;break;
	}
	FOR(i,1,m)if(b[i]==tb){
		tb=i;break;
	}
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans;
	RE 0;
}