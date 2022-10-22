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
const int mod=1e9+7;
int a[1000005],len;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
V<P<int,int> > v;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int cnt=0;
	int fir=1,mul=1;
	for(auto u:s){
		if(u=='0'){
			cnt++;
		}else {
			if(fir){
				fir=0;
				mul=cnt+1;
			}else{
				a[++len]=cnt;
			}
			cnt=0;
		}
	}
	if(fir){
		cout<<cnt;RE 0;
	}
	mul=mul*(cnt+1)%mod;
	v.PB(MP(1,-1));
	FOR(i,1,len){
		int now1=0,now2=0;
		while(!v.empty()&&v.back().S<a[i]){
			add(now1,v.back().F*(a[i]-v.back().S)%mod);
			add(now2,v.back().F);
			v.pop_back();
		}
		v.PB(MP(now2,a[i]));
		v.PB(MP(now1,-1));
	}
	int ans=0;
	for(auto u:v)add(ans,u.F);
	cout<<ans*mul%mod;
	RE 0;
}