#include<bits/stdc++.h>
typedef unsigned long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll f[52],fact[52],INF=1e18;
ll F(ll x){return x<=2?1:fact[x-2];}
ll MUL(ll a,ll b){return INF/a>b?a*b:INF;}
int fa[52],used[52];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int main(){
	int T=gi();
	f[0]=1;f[1]=1;f[2]=2;
	fact[0]=1;for(int i=1;i<=50;++i)fact[i]=MUL(fact[i-1],i);
	for(int i=3;i<=50;++i)for(int j=0;j<i;++j)f[i]=std::min(INF,f[i]+MUL(f[j],F(i-j)));
	while(T--){
		int n=gi();ll K=gi();
		if(f[n]<K){puts("-1");continue;}
		for(int i=1;i<=n;++i)fa[i]=i,used[i]=0;
		int i=1;
		while(i<=n){
			int L=1;
			while(1){
				if(K<=MUL(f[n-i+1-L],F(L))){//new cycle (len=L-1)
					printf("%d ",i+L-1);fflush(stdout);
					for(int j=i+1;j<=i+L-1;++j){
						ll s=f[n-i+1-L]*F(i+L-j);
						for(int k=i;k<i+L-1;++k)// try p[j]=k
							if(!used[k]&&(L==1||hd(j)!=hd(k))){
								if(K>s)K-=s;
								else{
									printf("%d ",k);fflush(stdout);
									used[k]=1;fa[hd(k)]=hd(j);
									break;
								}
							}
					}
					i+=L;break;
				}
				K-=f[n-i+1-L]*F(L);++L;
			}
		}
		puts("");fflush(stdout);
	}
	return 0;
}