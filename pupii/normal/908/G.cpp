#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char s[710];
int f[710][710][10][2];
il int add(int&a,int b){a+=b;if(a>=mod)a-=mod;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=0;i<10;++i)f[0][0][i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			for(int k=0;k<10;++k)
				for(int l=0;l<2;++l)
					for(int p=0,lim=l?9:s[i]-'0';p<=lim;++p)
						add(f[i][j+(k<=p)][k][l|(p<lim)],f[i-1][j][k][l]);
	int ans=0;
	for(int i=1;i<10;++i)
		for(int j=1,x=1;j<=n;++j,x=(1ll*x*10+1)%mod)
			add(ans,1ll*x*(f[n][j][i][0]+f[n][j][i][1])%mod);
	printf("%d\n",ans);
	return 0;
}