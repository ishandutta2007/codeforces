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
const int maxn=5e5+5;
int n,k,m,l[maxn],r[maxn],x[maxn];
typedef long long ll;
const ll mod=998244353;
int p[maxn],c[maxn];
ll f[maxn];
ll work(int k){
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));
	for(int i=1;i<=m;i++)
		if(x[i]>>k&1){
			c[l[i]]++;
			c[r[i]+1]--;
		}
		else p[r[i]]=max(p[r[i]],l[i]);
	int cur=0,ml=1;
	ll s=f[0]=1;
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
		if(c[i]){
			if(p[i]>=ml) return 0;
			f[i]=0;
		}
		else{
			ml=i+1;
			s=(s+(f[i]=s))%mod;
		}
		while(cur<p[i]) s=(s-f[cur++]+mod)%mod;
	}
	return s;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	m=readint();
	for(int i=1;i<=m;i++){
		l[i]=readint();
		r[i]=readint();
		x[i]=readint();
	}
	ll ans=1;
	for(int i=0;i<k;i++) ans=ans*work(i)%mod;
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}