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
int f[32][2][2][2],g[32][2][2][2];
il int solve(int n,int m,int K){
	if(n<0||m<0)return 0;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[31][0][0][0]=1;
	for(int p=30;~p;--p)
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					if(!f[p+1][i][j][k])continue;
					for(int a=0;a<2;++a)
						for(int b=0;b<2;++b){
							if(a&&!i&&!(n&(1<<p)))continue;
							if(b&&!j&&!(m&(1<<p)))continue;
							if((a^b)&&!k&&!(K&(1<<p)))continue;
							int _i=i,_j=j,_k=k;
							if(!a&&(n&(1<<p)))_i=1;
							if(!b&&(m&(1<<p)))_j=1;
							if(!(a^b)&&(K&(1<<p)))_k=1;
							f[p][_i][_j][_k]=(f[p][_i][_j][_k]+f[p+1][i][j][k])%mod;
							g[p][_i][_j][_k]=(g[p][_i][_j][_k]+g[p+1][i][j][k])%mod;
							if(a^b)g[p][_i][_j][_k]=(g[p][_i][_j][k]+1ll*(1<<p)*f[p+1][i][j][k])%mod;
						}
				}
	int ret=0;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				ret=(ret+(g[0][i][j][k]+f[0][i][j][k])%mod)%mod;
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int QAQ=gi();
	while(QAQ--){
		int x1=gi()-1,y1=gi()-1,x2=gi()-1,y2=gi()-1,k=gi()-1;
		printf("%d\n",(0ll+solve(x2,y2,k)-solve(x2,y1-1,k)-solve(x1-1,y2,k)+solve(x1-1,y1-1,k)+mod+mod)%mod);
	}
	return 0;
}