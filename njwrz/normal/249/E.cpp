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
#define y1 yyyy1111
using namespace std;
int mod=1e10;
__int128 one=1;
int get1(int x){
	int mul1=x,mul2=x+1;
	if(mul1&1)mul2/=2;else mul1/=2;
	mul1%=mod;mul2%=mod;
//	cout<<mul1<<' '<<mul2<<' '<<(int)()<<'\n';
	RE one*mul1*(mul2)%mod;
}
int get2(int x){
	int mul1=x,mul2=x+1,mul3=2*x+1;
	if(mul1%2==0)mul1/=2;else if(mul2%2==0)mul2/=2;else mul3/=2;
	if(mul1%3==0)mul1/=3;else if(mul2%3==0)mul2/=3;else mul3/=3;
	mul1%=mod;mul2%=mod;mul3%=mod;
	RE one*mul1*mul2*mul3%mod;
}
int get(int n,int m){
	if(n<m){
		int re=get1(n*n);
		int t=(get2(m-1)-get2(n-1)+mod)%mod;
		t=one*t*n%mod;
		RE (re+t+one*get1(n)*(m-n))%mod;
	}else {
		int re=get1(m*m);
		int t=(get2(n)-get2(m)+mod)%mod;
		t=one*t*m%mod;
		t=(t-one*get1(m-1)*(n-m)%mod+mod)%mod;
		RE (re+t)%mod;
	}
}
void solve(){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int ans[20]={},ff=1;
	rep(i,1,20){
		mod=(1e10)*i;
		ans[i]=(get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1)+mod*2)%(mod);
		if(i>1&&ans[i]!=ans[i-1]){
			ff=0;break;
		}
	}
	if(ff){
		cout<<ans[1]<<'\n';
	}else{
		V<int> out;
		while(ans[1]){
			out.PB(ans[1]%10);
			ans[1]/=10;
		}
		cout<<"...";
		while(out.size()<10)out.PB(0);
		reverse(ALL(out));
		for(auto u:out)cout<<u;
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}