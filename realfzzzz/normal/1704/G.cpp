#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
ll mod,g,invg;
ll ksm(ll a,ll b){
	ll c=1;
	while(b){
		if(b%2==1) c=c*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return c;
}
using poly=vector<ll>;
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
const int maxn=2e5+5;
int n,m,a[maxn],c[maxn];
ll b[maxn],d[maxn];
ll S(int n){
	return 1ll*n*(n+1)/2;
}
bool check(int k,ll x,ll y){
	if(x<0||x>k+1) return 0;
	return y>=S(x-1)&&y<=S(k)-S(k-x);
}
const ll mod2[]={998244353,167772161,469762049,1004535809},g2[]={3,3,3,3};
ll c2[maxn],f[maxn];
bool f2[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		m=read();
		for(int i=1;i<=m;i++) b[i]=read();
		for(int i=3;i<=n;i++) c[i]=a[i]+a[i-1]*2+a[i-2];
		for(int i=3;i<=m;i++) d[i]=b[i]+b[i-1]*2+b[i-2];
		for(int i=0;i<=n-m;i++) f2[i]=1;
		for(int t=0;t<4;t++){
			mod=mod2[t];
			g=g2[t];
			invg=ksm(g,mod-2);
			f[0]=0;
			for(int i=3;i<=n;i++) c2[i]=(c[i]+mod)%mod;
			for(int i=3;i<=m;i++){
				ll d2=(d[i]%mod+mod)%mod;
				f[0]=(f[0]+1ll*c2[i]*c2[i]%mod+c2[i]+d2*d2%mod-d2+mod)%mod;
			}
			for(int i=1;i<=n-m;i++)
				f[i]=(f[i-1]+1ll*c2[i+m]*c2[i+m]%mod+c2[i+m]-1ll*c2[i+2]*c2[i+2]%mod-c2[i+2]+mod*2)%mod;
			poly F(n+1),G(m+1);
			for(int i=3;i<=n;i++) F[i]=c2[i];
			for(int i=3;i<=m;i++) G[m-i+1]=(d[i]%mod+mod)%mod;
			int len=1;
			while(len<n+m+1) len*=2;
			F.resize(len);
			G.resize(len);
			F=FFT(F,1);
			G=FFT(G,1);
			for(int i=0;i<len;i++) F[i]=F[i]*G[i]%mod;
			F=FFT(F,0);
			for(int i=0;i<=n-m;i++) f2[i]&=f[i]==F[i+m+1]*2%mod;
		}
		bool flag=0;
		for(int i=0;i<=n-m;i++) if(f2[i]){
			ll x,y;
			x=a[i+1]+a[i+2]-b[1]-b[2]+(i+3)/2;
			y=b[1]-a[i+1]+S((i+1)/2)*2;
			if(!check(i+1,x,y)) continue;
			flag=1;
			vector<int> ans;
			int k=i+1;
			for(int j=1;j<=i+2;j++){
				bool fl=check(k-1,x-1,y-i+j-2);
				if(fl){
					k--;
					x--;
					y-=i-j+2;
				}
				if(fl^(i%2==j%2)) ans.push_back(j);
			}
			for(int j=i+3;j<=i+m;j++) if(d[j-i]>c[j]) ans.push_back(j);
			printf("%d\n",(int)ans.size());
			for(int j:ans) printf("%d ",j);
			printf("\n");
			break;
		}
		if(!flag) printf("-1\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}