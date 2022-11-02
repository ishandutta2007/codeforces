#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,ans,f[200020],num[200020],siz[200020];
struct edge{
	int x,y,z;
}e[200200];
int cmp(edge x,edge y){
	return x.z>y.z;
}
int get(int x){
	if (f[x]==x) return x;
	f[x]=get(f[x]);
	return f[x];
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e,e+m,cmp);
	//for (int i=0;i<m;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].z);
	for (int i=1;i<=n;i++) f[i]=i,siz[i]=1;;
	for (int i=0;i<m;i++){
		int o=get(e[i].x),p=get(e[i].y);
		if (o==p){
			if (num[o]<siz[o]) num[o]++,ans+=e[i].z;
		}
		else if (num[o]+num[p]<siz[o]+siz[p]){
			f[o]=p;
			num[p]+=num[o]+1;
			siz[p]+=siz[o];
			ans+=e[i].z;
		}
	}
	printf("%d\n",ans);
}