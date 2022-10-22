#pragma GCC optimize("Ofast")
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
using namespace std;
int a[100005],p[100005];
int n;
bool check(int x){
	FILL(p,0);
	FOR(i,1,x){
		p[i*2]=a[i];
	}
	int t=x;
	FOR(i,x*2+2,n){
		p[i]=a[++t];
	}
	for(int i=1;i<=2*x+1;i+=2)p[i]=a[++t];
//	FOR(i,1,n)cout<<p[i]<<' ';cout<<'\n';
	rep(i,1,n){
		if(p[i]==p[i+1]&&i<=x*2)RE 0;
	}
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,n)p[i]=a[i];
	int ans,l,mid,r;ans=0;
	l=1;r=(n-1)/2;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans<<'\n';
	FOR(i,1,n)cout<<p[i]<<' ';
	RE 0;
}