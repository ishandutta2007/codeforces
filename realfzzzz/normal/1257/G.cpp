#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn];
typedef long long ll;
const ll mod=998244353,g=3,invg=332748118;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b){
		if(b%2==1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
typedef vector<ll> poly;
poly FFT(poly F,bool flag){
	int n=F.size();
	vector<int> rev(n);
	for(int i=1;i<n;i++) rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
	for(int i=0;i<n;i++) if(i<rev[i]) swap(F[i],F[rev[i]]);
	for(int i=1;i<n;i*=2){
		ll wn=ksm(flag?g:invg,(mod-1)/(i*2));
		for(int j=0;j<n;j+=i*2){
			ll w=1;
			for(int k=j;k<j+i;k++){
				ll t=F[k+i]*w%mod;
				F[k+i]=(F[k]-t+mod)%mod;
				F[k]=(F[k]+t)%mod;
				w=w*wn%mod;
			}
		}
	}
	if(!flag){
		ll invn=ksm(n,mod-2);
		for(int i=0;i<n;i++) F[i]=F[i]*invn%mod;
	}
	return F;
}
poly solve(int l,int r){
	if(l==r){
		poly F(a[r]+1);
		for(int i=0;i<=a[r];i++) F[i]=1;
		return F;
	}
	int mid=l+(r-l)/2;
	poly F=solve(l,mid),G=solve(mid+1,r);
	int n=F.size(),m=G.size(),len=1;
	while(len<n+m-1) len*=2;
	F.resize(len);
	G.resize(len);
	F=FFT(F,1);
	G=FFT(G,1);
	for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
	F=FFT(F,0);
	F.resize(n+m-1);
	return F;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		int p=readint();
		if(!mp.count(p)){
			int res=mp.size();
			mp[p]=res+1;
		}
		a[mp[p]]++;
	}
	printf("%lld\n",solve(1,mp.size())[n/2]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}