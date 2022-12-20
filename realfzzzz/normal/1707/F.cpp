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
const int maxn=1e7+5;
int n,m,t,w,q,e[maxn];
int n2,c[maxn],s[maxn],rev[maxn],lg[maxn*2];
int b[maxn*2],f[maxn*2];
void pushup(int x){
	int lc=x<<1,rc=x<<1|1;
	if(b[lc]==-2||b[rc]==-2){
		b[x]=-2;
		return;
	}
	f[x]=f[lc]+f[rc];
	if(t>>lg[x]&1){
		if(b[lc]<0) b[x]=b[rc];
		else if(b[rc]<0) b[x]=b[lc];
		else b[x]=b[lc]==b[rc]?b[rc]:-2;
	}
	else{
		if(b[lc]<0||b[rc]<0){
			b[x]=-1;
			f[x]+=b[lc]<0&&b[rc]<0;
		}
		else b[x]=b[lc]^b[rc];
	}
}
void modify(int x,int k){
	int u=x&(n2-1);
	if(e[x]>=0){
		c[u]--;
		s[u]^=e[x];
	}
	if(k>=0){
		c[u]++;
		s[u]^=k;
	}
	e[x]=k;
	x=n2|rev[u];
	if(c[u]==n/n2){
		b[x]=t<n2||!s[u]?s[u]:-2;
		f[x]=0;
	}
	else{
		b[x]=t<n2?-1:0;
		f[x]=n/n2-c[u]-1;
	}
	while(x^1) pushup(x>>=1);
}
ll ksm(ll a,ll b,ll p){
	ll s=1;
	while(b){
		if(b%2==1) s=s*a%p;
		a=a*a%p;
		b/=2;
	}
	return s;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	t=read();
	w=read();
	memset(e,-1,sizeof(e));
	n2=n&-n;
	for(int i=1;i<n2;i++) rev[i]=rev[i>>1]>>1|(i&1?n2>>1:0);
	for(int i=2;i<n2*2;i++) lg[i]=lg[i>>1]+1;
	if(t<n2) memset(b,-1,sizeof(b));
	for(int i=n2;i<n2*2;i++) f[i]=n/n2-1;
	for(int i=n2-1;i>0;i--) pushup(i);
	while(m--){
		int x=read()-1;
		modify(x,read());
	}
	q=read();
	while(q--){
		int x=read()-1;
		modify(x,read());
		ll p=read();
		if(b[1]==-2) printf("0\n");
		else printf("%lld\n",ksm((1<<w)%p,f[1]+(b[1]<0),p));
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}