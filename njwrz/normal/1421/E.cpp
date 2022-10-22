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
P<int,int> p[200005]; 
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i],p[i]=MP(a[i],i);
	if(n==1){
		cout<<a[1];RE 0;
	}
	sort(p+1,p+n+1,greater<P<int,int> > ());
	int ans=-1e18;
	if(n&1){
		int sum=0;
		int mid=(n+1)/2;
		bool f=1;
		FOR(i,1,mid){
			if(!(p[i].S&1)){
				f=0;break;
			}
		}
		FOR(i,1,n)sum-=p[i].F;
		FOR(i,0,n){
			sum+=2*p[i].F;
			if(i%3==mid%3&&(!f||i!=mid)){
				gmax(ans,sum);
			}
		}
		swap(p[mid].F,p[mid+1].F);
		sum=0;
		FOR(i,1,n)sum-=p[i].F;
		FOR(i,1,mid){
			sum+=p[i].F*2;
		}
		gmax(ans,sum);
	}else{
		int sum=0;
		FOR(i,1,n)sum-=p[i].F;
		FOR(i,0,n){
			sum+=2*p[i].F;
			if(i%3==((n-2)/2)%3){
				gmax(ans,sum);
			}
		}
	}
	cout<<ans;
	RE 0;
}