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
int n,a[maxn*2],b[maxn],t;
bool v[maxn*2];
int lst[maxn*2];
const ll mod=1e9+7;
inline int lowbit(int x){
	return x&-x;
}
ll c[maxn*2];
void modify(int x,ll k){
	while(x){
		c[x]=(c[x]+k)%mod;
		x-=lowbit(x);
	}
}
ll query(int x){
	ll s=0;
	while(x<=n*2){
		s=(s+c[x])%mod;
		x+=lowbit(x);
	}
	return s;
}
ll f[maxn*2];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++){
		int x=readint();
		b[i]=readint();
		a[b[i]]=x;
	}
	t=readint();
	for(int i=1;i<=t;i++) v[b[readint()]]=1;
	int l=0;
	for(int i=n*2;i>0;i--) if(v[i]){
		if(a[i]<l) v[i]=0;
		else{
			lst[i]=l;
			l=a[i];
		}
	}
	for(int i=1;i<=n*2;i++) if(a[i]){
		f[i]=(query(a[i])+1)%mod;
		modify(a[i],f[i]);
	}
	ll ans=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n*2;i++) if(a[i]){
		if(v[i]) ans=(ans+query(lst[i]+1)+1)%mod;
		modify(a[i],f[i]);
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}