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
int mod=998244353,finv[200005],inv[200005],f[200005];
int p[200005];
void solve(){
	int n,m=0;
	cin>>n;
	int cnt=0,cntev=0; 
	FOR(i,1,n){
		char c;
		cin>>c;
		if(c=='1'){
			cnt++;
		}else {
			if(cnt&1){
				p[++m]=1;cntev+=cnt/2;
			}else cntev+=cnt/2;
			p[++m]=0;
			cnt=0;
		}
	}
	if(cnt&1){
		p[++m]=1;cntev+=cnt/2;
	}else cntev+=cnt/2;
	if(!m){
		cout<<1<<'\n';RE ;
	}
	int cntm=m;
	if(p[1])cntm--;
	FOR(i,2,m){
		if(p[i]){
			cntm--;
		}
	}
//	cout<<cntev<<' '<<cntm<<'\n';
	cout<<f[cntev+cntm]*finv[cntm]%mod*finv[cntev]%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	inv[1]=finv[0]=finv[1]=f[0]=f[1]=1;
	FOR(i,2,200000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		f[i]=f[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}