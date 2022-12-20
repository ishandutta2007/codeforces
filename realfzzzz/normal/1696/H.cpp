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
const int maxn=600+5;
int n,m,a[maxn],n1=0,a1[maxn],n2=0,a2[maxn];
int ub1[maxn],ub2[maxn];
const ll mod=1e9+7;
ll pw[maxn];
ll f[maxn][maxn],sf[maxn][maxn],g[maxn][maxn],sg[maxn][maxn];
ll s[maxn],h[maxn][maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,[](int a,int b){
		return abs(a)>abs(b);
	});
	for(int i=1;i<=n;i++) (a[i]>=0?a1[++n1]:a2[++n2])=i;
	ub1[0]=ub2[0]=1;
	for(int i=1;i<=n;i++){
		ub1[i]=ub1[i-1];
		while(ub1[i]<=n1&&a1[ub1[i]]<=i) ub1[i]++;
		ub2[i]=ub2[i-1];
		while(ub2[i]<=n2&&a2[ub2[i]]<=i) ub2[i]++;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	sf[0][0]=1;
	for(int i=1;i<=n1;i++){
		sf[i][0]=1;
		for(int j=1;j<=i;j++){
			f[i][j]=sf[i-1][j-1]*a[a1[i]]%mod;
			sf[i][j]=(sf[i-1][j]+f[i][j])%mod;
		}
	}
	ll ans=0;
	if(m%2==1){
		sg[n2+1][0]=1;
		for(int i=n2;i>0;i--){
			sg[i][0]=1;
			for(int j=1;j<=n2-i+1;j++){
				g[i][j]=sg[i+1][j-1]*(a[a2[i]]+mod)%mod;
				sg[i][j]=(sg[i+1][j]+g[i][j])%mod;
			}
		}
		for(int i=1;i<=n2-m+1;i++) ans=(ans+g[i][m]*pw[i-1]%mod)%mod;
		memset(g,0,sizeof(g));
		memset(sg,0,sizeof(sg));
	}
	sg[0][0]=1;
	for(int i=1;i<=n2;i++){
		sg[i][0]=1;
		for(int j=1;j<=i;j++){
			g[i][j]=sg[i-1][j-1]*(a[a2[i]]+mod)%mod;
			sg[i][j]=(sg[i-1][j]+g[i][j])%mod;
		}
	}
	if(m%2==0) for(int i=m;i<=n2;i++) ans=(ans+g[i][m]*pw[n2-i]%mod)%mod;
	for(int i=m;i<=n1;i++) ans=(ans+f[i][m]*pw[n-i-ub2[a1[i]]+1]%mod)%mod;
	for(int i=m;i<=n2;i++)
		if(m%2==0) ans=(ans+g[i][m]*(pw[n1-ub1[a2[i]]+1]-1)%mod*pw[n2-i]%mod)%mod;
		else for(int j=ub1[a2[i]];j<=n1;j++)
			ans=(ans+a[a1[j]]*sg[i-1][m-1]%mod*pw[n-j-i]%mod)%mod;
	for(int i=n2;i>0;i--) s[i]=(s[i+1]+(a[a2[i]]+mod)*pw[n2-i]%mod)%mod;
	for(int i=1;i<=n1;i++) for(int j=1;j<=n2;j++){
		int r=max(a1[i],a2[j]);
		h[i][j]=a[a1[i]]*(a[a2[j]]+mod)%mod;
		for(int k=ub1[r];k<=n1;k++)
			h[i][j]=(h[i][j]+pw[n1-k]*a[a1[i]]%mod*a[a1[k]]%mod)%mod;
		for(int k=ub2[r];k<=n2;k++)
			h[i][j]=(h[i][j]+pw[n2-k]*(a[a2[j]]+mod)%mod*(a[a2[k]]+mod)%mod)%mod;
		int c=ub2[r];
		for(int k=ub1[r];k<=n1;k++){
			while(c<=n2&&1ll*a[a2[j]]*a[a2[c]]>1ll*a[a1[i]]*a[a1[k]]) c++;
			h[i][j]=(h[i][j]+pw[n1-k]*(pw[n2-c+1]-1)%mod*a[a1[i]]%mod*a[a1[k]]%mod)%mod;
			h[i][j]=(h[i][j]+(s[ub2[r]]-s[c]+mod)%mod*pw[n1-k]%mod*(a[a2[j]]+mod)%mod)%mod;
		}
	}
	for(int i=1;i<m;i++) for(int j=i;j<=n1;j++) for(int k=m-i;k<=n2;k++){
		int r=max(a1[j],a2[k]);
		if((m-i)%2==0) ans=(ans+f[j][i]*g[k][m-i]%mod*pw[n-ub1[r]-ub2[r]+2]%mod)%mod;
		else ans=(ans+sf[j-1][i-1]*sg[k-1][m-i-1]%mod*h[j][k]%mod)%mod;
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}