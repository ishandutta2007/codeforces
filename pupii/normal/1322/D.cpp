// ka ni ma de chang
#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int L[2010],s[2010],cost[4010],c[4010];
std::vector<int>f[2010][4010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)L[i]=gi(),++c[L[i]];
	for(int i=1;i<=n+m;++i)c[i+1]+=c[i]>>1;
	for(int i=1;i<=n;++i)s[i]=gi();
	for(int i=1;i<=n+m;++i)cost[i]=gi();
	for(int i=n+1;i;--i)
		for(int j=0;j<=n+m;++j)
			f[i][j].resize(c[j]+1,-1e9);
	f[n+1][0]={0};
	for(int i=n;~i;--i)
		for(int j=0;j<=n+m;++j)
			for(int k=f[i+1][j].size()-1;~k;--k){
				if(f[i+1][j][k]<-1e8)continue;
				if(!i){if(k)assert(k>>1<f[i+1][j+1].size()),cxk(f[i+1][j+1][k>>1],f[i+1][j][k]+cost[j+1]*(k>>1));}
				else{
					cxk(f[i][j][k],f[i+1][j][k]);
					if(L[i]==j)assert(k+1<f[i][L[i]].size()),cxk(f[i][L[i]][k+1],f[i+1][j][k]-s[i]+cost[j]);
					else if(L[i]>j)assert(k>>1<f[i+1][j+1].size()),cxk(f[i+1][j+1][k>>1],f[i+1][j][k]+cost[j+1]*(k>>1));
				}
			}
	int ans=-1e9;
	for(int j=0;j<=n+m;++j)for(int k=0;k<2&&k<f[1][j].size();++k)cxk(ans,f[1][j][k]);
	printf("%d\n",ans);
	return 0;
}