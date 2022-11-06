#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=400000,lgn=19;
ll f[maxn+10][lgn+1],lst; int g[maxn+10][lgn+1],h[maxn+10][lgn+1],p[maxn+10][lgn+1],q,cnt;
bool isntp[maxn+10][lgn+1];
void add(int x,int fa,int v){
	int t=fa;
	for(int i=lgn;i>=0;--i) if(h[t][i]<v) t=p[t][i];
	g[x][0]=t; f[x][0]=h[x][0]=v; p[x][0]=fa; isntp[x][0]=1;
	for(int i=1;i<=lgn;++i){
		f[x][i]=f[x][i-1]+f[g[x][i-1]][i-1];
		g[x][i]=g[g[x][i-1]][i-1];
		isntp[x][i]=isntp[x][i-1]&&isntp[g[x][i-1]][i-1];
		h[x][i]=max(h[x][i-1],h[p[x][i-1]][i-1]);
		p[x][i]=p[p[x][i-1]][i-1];
	}
}
int main(){
	cnt=1; isntp[1][0]=1;
	scanf("%d",&q);
	for(;q--;){
		int op; ll p,q;
		scanf("%d%lld%lld",&op,&p,&q);
		p^=lst; q^=lst;
		if(op==1) add(++cnt,p,q);
		else{
			int ans=0;
			for(int i=lgn;i>=0;--i)
				if(isntp[p][i]&&f[p][i]<=q) q-=f[p][i],p=g[p][i],ans+=1<<i;
			printf("%d\n",lst=ans);
		}
	}
}