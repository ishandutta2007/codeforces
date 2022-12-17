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
const int maxn=1e5+5,maxm=17+5,maxs=(1<<17)+5;
int n,m,a[maxn][3];
const ll mod=998244353,inv2=499122177;
void FWT(ll* f,int n,bool flag){
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++){
			ll t=f[k+i];
			f[k+i]=(f[k]-t+mod)%mod*(flag?1:inv2)%mod;
			f[k]=(f[k]+t)%mod*(flag?1:inv2)%mod;
		}
}
ll x[3],pw[8][maxn],f[8][maxs],g[8];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=0;i<3;i++) x[i]=read()%mod;
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) a[i][j]=read();
	for(int i=0;i<8;i++){
		pw[i][0]=1;
		for(int j=0;j<3;j++)
			pw[i][1]=(pw[i][1]+((i>>j&1)?(mod-x[j])%mod:x[j]))%mod;
		for(int j=2;j<=n;j++) pw[i][j]=pw[i][j-1]*pw[i][1]%mod;
	}
	for(int i=0;i<8;i++){
		for(int j=1;j<=n;j++){
			int s=0;
			for(int k=0;k<3;k++) if(i>>k&1) s^=a[j][k];
			f[i][s]++;
		}
		FWT(f[i],1<<m,1);
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<8;j++) g[j]=f[j][i];
		FWT(g,8,0);
		f[0][i]=1;
		for(int j=0;j<8;j++) f[0][i]=f[0][i]*pw[j][g[j]]%mod;
	}
	FWT(f[0],1<<m,0);
	for(int i=0;i<(1<<m);i++) printf("%lld ",f[0][i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}