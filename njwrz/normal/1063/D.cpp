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
int n,len,k;
void solve1(){
	int re=-1;
	FOR(i,0,n){
		int res=k%(n+i);
		if(!res)res+=n+i;
		if(res<len)continue;
		res-=len;
		if(res>len)continue;
		if(i>=res&&i-(n-len)<=res+1){
			gmax(re,i);
		}
	}
	cout<<re;
}
void solve2(){
	int re=-1;
	if(k<=2*len){
		int r=k+1-2*len+n,l=k-len;
		gmax(l,0ll),gmin(r,n);
		if(l<=r)gmax(re,r);
	}
	FOR(i,1,k/n){
		int l=0,r=n;
		if(k-len-i*n<0||k+1-n*i-2*len+n<0)continue;
		gmin(r,(k-len-i*n)/i);gmin(r,(k+1-n*i-2*len+n)/(i+1));
		gmax(l,(k-n*i-2*len+i-1)/i);gmax(l,(k-n*i-len+i)/(i+1));
		if(l<=r)gmax(re,r);
	}
	cout<<re;
}
signed main(){
//	freopen("mk.in","r",stdin);
//	freopen("mk.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l,r;
	cin>>n>>l>>r>>k;
	len=(r-l+n)%n+1;
	if(k<len){
		cout<<-1;RE 0;
	}
	if(n<=sqrt(k))solve1();else solve2();
	RE 0;
}