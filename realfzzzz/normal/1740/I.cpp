// LUOGU_RID: 92582889
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
const int maxn=1e6+5;
int n,m,k,a[maxn],d,b[maxn];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
const ll inf=9e18;
ll f[maxn],f2[maxn];
int q[maxn*2],hd,tl;
void work(int l,int r,ll k,ll b){
	hd=1;
	tl=0;
	auto val=[k](int x){
		int y=x<0?x+m:x;
		return f[y]<inf?f[y]-k*x:inf;
	};
	for(int i=-m;i<m-l;i++){
		while(hd<=tl&&val(i)<val(q[tl])) tl--;
		q[++tl]=i;
		if(i+l>=0){
			while(q[hd]<i+l-r) hd++;
			if(val(q[hd])<inf)
				f2[i+l]=min(f2[i+l],val(q[hd])+k*(i+l)+b);
		}
	}
}
ll s[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	k=read();
	for(int i=0;i<n;i++) a[i]=read();
	d=gcd(n,k);
	a[n]=a[0];
	for(int i=0;i<n;i++) b[i]=(a[i+1]-a[i]+m)%m;
	for(int i=0;i<d;i++){
		a[i]=0;
		int u=i;
		do{
			a[(u+k)%n]=(a[u]+b[u])%m;
			u=(u+k)%n;
		}while(u!=i);
		if(a[i]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<m;i++) f[i]=inf;
	for(int i=0;i<d;i++){
		for(int j=0;j<m;j++) f2[j]=inf;
		for(int j=0;j<m;j++){
			s[j]=0;
			for(int k=i;k<n;k+=d)
				s[j]=(s[j]+min((j+a[k])%m,m-(j+a[k])%m));
		}
		int l=0;
		for(int j=2;j<=m;j++)
			if(j==m||(j>l+1&&s[j]+s[j-2]!=s[j-1]*2)){
				work(l,j-1,s[j-1]-s[j-2],s[l]-(s[j-1]-s[j-2])*l);
				l=j;
			}
		for(int j=0;j<m;j++) f[j]=f2[j];
	}
	ll ans=inf;
	int s=0;
	for(int i=0;i<k;i++) s=(s+a[i])%m;
	for(int i=0;i<m;i++) if((1ll*k/d*i+s)%m==a[n]) ans=min(ans,f[i]);
	printf("%lld\n",ans<inf?ans:-1);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}