#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
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
std::vector<int>G[200010];
int f[200010][2],g[3],_g[3];
il vd inc(int&a,int b){a+=b;if(a>=mod)a-=mod;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=2;i<=n;++i)G[gi()].push_back(i);
	for(int x=n;x;--x){
		if(G[x].empty())f[x][0]=f[x][1]=1;
		else{
			g[0]=1,g[1]=g[2]=0;
			for(auto i:G[x]){
				memset(_g,0,sizeof _g);
				for(int j=0;j<3;++j)
					for(int k=0;k<2;++k)
						inc(_g[std::min(j+k,2)],1ll*g[j]*f[i][k]%mod);
				memcpy(g,_g,sizeof g);
			}
			f[x][0]=(g[0]+g[2])%mod;f[x][1]=(g[1]+g[2])%mod;
		}
	}
	printf("%d\n",f[1][0]);
	return 0;
}