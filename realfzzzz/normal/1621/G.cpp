#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
int n,a[maxn],ord[maxn],s[maxn],tp;
const ll mod=1e9+7;
ll c[maxn];
inline int lowbit(int x){
	return x&-x;
}
void modify(int x,ll k){
	while(x<=n){
		c[x]=(c[x]+k)%mod;
		x+=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x){
		s=(s+c[x])%mod;
		x-=lowbit(x);
	}
	return s;
}
ll f[maxn],g[maxn],h[maxn];
vector<int> vec[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) ord[i]=i;
		sort(ord+1,ord+n+1,[](int x,int y){
			if(a[x]!=a[y]) return a[x]<a[y];
			return x>y;
		});
		for(int i=1;i<=n;i++) a[ord[i]]=i;
		tp=0;
		for(int i=n;i>0;i--)
			if(a[i]>a[s[tp]]) s[++tp]=i;
		for(int i=1;i<=n;i++){
			f[i]=(query(a[i])+1)%mod;
			modify(a[i],f[i]);
		}
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=n;i>0;i--){
			g[i]=(query(n-a[i]+1)+1)%mod;
			modify(n-a[i]+1,g[i]);
		}
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=tp;i++)
			vector<int>().swap(vec[i]);
		for(int i=n;i>0;i--){
			int l=1,r=tp;
			while(l<r){
				int mid=l+(r-l)/2;
				if(a[i]<=a[s[mid]]) r=mid;
				else l=mid+1;
			}
			if(s[r]!=i) vec[r].push_back(i);
		}
		for(int i=1;i<=tp;i++){
			modify(n-a[s[i]]+1,h[s[i]]=1);
			for(int j:vec[i]){
				h[j]=query(n-a[j]+1);
				modify(n-a[j]+1,h[j]);
			}
			for(int j:vec[i])
				modify(n-a[j]+1,(mod-h[j])%mod);
			modify(n-a[s[i]]+1,mod-1);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+(g[i]-h[i]+mod)%mod*f[i]%mod)%mod;
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}