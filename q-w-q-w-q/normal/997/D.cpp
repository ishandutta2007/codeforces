#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
int n,m,k,x,y,ans;
int h[4001],to[8001],ne[8001];
int f[8001][76],g[4001][76],sum[4001][76],s1[76],s2[76];
int c[76][76];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=h[x];
	h[x]=k;
}
inline void work(int n){
	for(int i=0;i<(n<<1)-2;i++) f[i][0]=1;
	for(int i=1;i<=n;i++) g[i][0]=1;
	for(int l=2;l<=k;l+=2){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			for(int k=h[i];k!=-1;k=ne[k])
				for(int j=0;j<l;j+=2)
					sum[i][j]=add(sum[i][j],f[k][j]);
		for(int i=1;i<=n;i++){
			for(int k=h[i];k!=-1;k=ne[k]){
				int x=to[k];
				f[k][l]=0;
				for(int j=0;j<l;j+=2) f[k][l]=(f[k][l]+1ll*f[k][l-j-2]*sub(sum[x][j],f[k^1][j]))%mod;
			}
			g[i][l]=0;
			for(int j=0;j<l;j+=2) g[i][l]=(g[i][l]+1ll*g[i][l-j-2]*sum[i][j])%mod;
		}
	}
}
int main(){
	cin>>n>>m>>k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<n;i++){
		cin>>x>>y;
		link(x,y,(i<<1)-2);
		link(y,x,(i<<1)-1);
	}
	work(n);
	for(int i=0;i<=k;i+=2)
		for(int j=1;j<=n;j++)
			s1[i]=add(s1[i],g[j][i]);
	n=m,memset(h,-1,sizeof(h));
	for(int i=1;i<n;i++){
		cin>>x>>y;
		link(x,y,(i<<1)-2);
		link(y,x,(i<<1)-1);
	}
	work(n);
	for(int i=0;i<=k;i+=2)
		for(int j=1;j<=n;j++)
			s2[i]=add(s2[i],g[j][i]);
	c[0][0]=1;
	for(int i=1;i<=k;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++) c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	for(int i=0;i<=k;i+=2) ans=(ans+1ll*s1[i]*s2[k-i]%mod*c[k][i])%mod;
	cout<<ans;
}