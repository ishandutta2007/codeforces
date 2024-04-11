#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
const int maxn=100003;
struct edge{
	   int x,y,w;
	   bool operator <(const edge &b) const {return w>b.w;}
}e[maxn];
int n,m,a[maxn],f[maxn],s[maxn];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=m;++i){
			scanf("%d%d",&e[i].x,&e[i].y);
			e[i].w=min(a[e[i].x],a[e[i].y]);
	}
	sort(e+1,e+m+1);;
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++){
			int x=find(e[i].x),y=find(e[i].y);
			if(x!=y)ans+=1ll*e[i].w*s[x]*s[y],f[x]=y,s[y]+=s[x];
	}
	printf("%.9lf\n",ans*2.0/n/(n-1));
	return 0;
}