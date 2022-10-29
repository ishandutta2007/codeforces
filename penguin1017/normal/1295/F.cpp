#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=51;
const ll mod=998244353;
int L[N],R[N];
vector<vi> g[N];
vi p[N],H[N];
ll U=1,D=1,inv[120],Lag[120];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void pre(){
	inv[0]=1,inv[1]=1;
	rep(i,2,60){
		int k=mod/i,r=mod%i;
		inv[i]=-inv[r]*k%mod;
		inv[i]+=mod;
	}
	rep(i,2,60)inv[i]=inv[i]*inv[i-1]%mod;
}
ll Lagrange(int h,vi vec,ll sum,int id,int fir,int las){
//	for(auto u:vec)cout<<u<<' ';
//	cout<<"vec\n";
//	cout<<fir<<' '<<las<<"fir\n";
	if(id)H[id].pb(h+1);
	vi v;
	v.clear();
	int sz=vec.size();
	if(h+2<=sz){
		rep(i,0,h+2)Lag[i+1]=(vec[i]+Lag[i])%mod;
		rep(i,1,h+3)Lag[i]=(Lag[i]+sum)%mod;
		int tot=0;
		rep(i,fir,las){
			if(tot==h+3)break;
			++tot;
			ll jie=1;
			if(i<=h+2){
				v.pb(Lag[i]);
			//	cout<<Lag[i]<<"born\n";
				continue;
			}
			rep(j,1,h+3)jie=jie*(i-j)%mod;
			ll res=0;
			rep(j,1,h+3){
				res=(res+Lag[j]*inv[j-1]%mod*inv[h+2-j]%mod*jie%mod*quick(i-j,mod-2)%mod*(((h+2-j)&1)?-1:1))%mod;
			}
			if(res<0)res+=mod;
		//	cout<<i<<' '<<res<<"born2\n";
			v.pb(res);
		}
		if(id)g[id].pb(v);
		ll res=0;
		if(las-1<=h+2)return Lag[las-1];
		int i=las-1;
		ll jie=1;
		rep(j,1,h+3)jie=jie*(i-j)%mod;
		rep(j,1,h+3)res=(res+Lag[j]*inv[j-1]%mod*inv[h+2-j]%mod*jie%mod*quick(i-j,mod-2)%mod*(((h+2-j)&1)?-1:1))%mod;
		if(res<0)res+=mod;
		return res;
	}
	else{
		rep(i,0,sz)Lag[i+1]=(vec[i]+Lag[i])%mod;
	//	cout<<' '<<sz<<' '<<Lag[2]<<"???\n";
		rep(i,1,sz+1)Lag[i]=(Lag[i]+sum)%mod;
		if(id){
			rep(i,fir,las)v.pb(Lag[i]);
			g[id].pb(v);
		}	
	//	cout<<las-1<<' '<<Lag[2]<<"why\n";
		return Lag[las-1];
	} 
} 
int main(){
	pre();
	int n;
	scanf("%d",&n);
	per(i,1,n+1)scanf("%d%d",&L[i],&R[i]),D=D*(R[i]-L[i]+1)%mod;
	rep(i,2,n+1)L[i]=max(L[i],L[i-1]); 
	per(i,1,n)R[i]=min(R[i],R[i+1]);
	L[n+1]=R[n+1]=R[n];
	rep(i,1,n+1){
		if(L[i]>R[i]){
			printf("0");
			return 0;
		}
	}
	vi v;
	v.clear();
	if(R[1]==L[1])v.pb(1);
	else v.pb(1),v.pb(1);
	g[1].pb(v);
	v.clear();
	p[1].pb(L[1]);
	v.pb(0);
	g[1].pb(v);
	p[1].pb(R[1]+1);
	H[1].pb(0);
	ll sum;
	rep(i,1,n+1){
		sum=0;
		int sz=p[i].size(),id=0;
		--sz;
		while(id<sz&&p[i][id+1]<=L[i+1])sum=(Lagrange(H[i][id],g[i][id],sum,0,max(L[i+1],p[i][id])-p[i][id]+1,p[i][id+1]-p[i][id]+1))%mod,++id;
		for(;id<sz;++id){
			sum=(Lagrange(H[i][id],g[i][id],sum,i+1,max(L[i+1],p[i][id])-p[i][id]+1,p[i][id+1]-p[i][id]+1))%mod;
			p[i+1].pb(max(L[i+1],p[i][id]));
		//	cout<<i<<' '<<p[i][id]<<' '<<L[i+1]<<' '<<p[i][id+1]<<' '<<id<<' '<<sum<<"sum\n";
		}
		if(R[i+1]<p[i][id]){
			v.clear();
			v.pb(0);
			g[i+1].pb(v);
			p[i+1].pb(R[i+1]+1);
		}
		else{
			v.clear();
			if(R[i+1]==p[i][id])v.pb(sum);
			else v.pb(sum),v.pb(sum);
			g[i+1].pb(v);
			H[i+1].pb(0);
			p[i+1].pb(max(L[i+1],p[i][id]));
			///
			v.clear();
			v.pb(0);
			g[i+1].pb(v);
			p[i+1].pb(R[i+1]+1);
		}
	}
	ll ans=sum*quick(D,mod-2)%mod;
//	cout<<sum<<' '<<D<<"check\n";
	printf("%lld",ans);
}
/*
2 
2 4
1 3

2
4 5
1 2
*/