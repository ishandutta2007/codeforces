#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int f[2][101][101][101],fC[201][201];
int Trans(int a,int b){return a==1?1:fC[b-1][a-1];}
void add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),K=gi(),ans=0;
	fC[0][0]=1;
	for(int i=1;i<=200;++i){
		fC[i][0]=1;
		for(int j=1;j<=i;++j)fC[i][j]=std::min(K+1,fC[i-1][j-1]+fC[i-1][j]);
	}
	int t=0;
	for(int i=1;i<=n;++i)f[t][i][i][1]=1;
	for(int i=2;i<=m;++i){
		memset(f[!t],0,sizeof f[!t]);
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				for(int l=1;l<=K;++l)
					if(f[t][j][k][l])
						for(int o=k;o+j<=n;++o){
							if(l*Trans(k,o)>K)break;
							add(f[!t][j+o][o-k][l*Trans(k,o)],f[t][j][k][l]%mod);
						}
		t=!t;
		for(int j=1;j<=n;++j)
			for(int l=1;l<=K;++l)
				ans=(ans+1ll*f[t][j][0][l]*(m-i+1))%mod;
	}
	printf("%d\n",ans);
	return 0;
}