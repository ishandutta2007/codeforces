#include<bits/stdc++.h>
#define LL long long
#define inf 2000000000000LL
using namespace std;
struct flight{
	int d,f,t,c;
}f[1000010];
int cmp(flight x,flight y){
	return x.d<y.d;
}
int n,m,k;
LL ans,gsum[1000010],bsum[1000010],tmp[1000010];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++) scanf("%d%d%d%d",&f[i].d,&f[i].f,&f[i].t,&f[i].c);
	sort(f,f+m,cmp);
	for (int i=1;i<=n;i++) tmp[i]=inf;
	int l=0;
	gsum[0]=inf*n;
	for (int i=1;i<=f[m-1].d;i++){
		gsum[i]=gsum[i-1];
		while (l<m&&f[l].d<i){
			if (f[l].t==0){
				gsum[i]=gsum[i]-tmp[f[l].f];
				tmp[f[l].f]=min(tmp[f[l].f],(LL)f[l].c);
				gsum[i]=gsum[i]+tmp[f[l].f];
			}
			l++;
		}
	}
	for (int i=1;i<=n;i++) tmp[i]=inf;
	l=m-1;
	bsum[f[m-1].d+1]=inf*n;
	for (int i=f[m-1].d;i;i--){
		bsum[i]=bsum[i+1];
		while (l&&f[l].d>=i){
			if (f[l].f==0){
				bsum[i]=bsum[i]-tmp[f[l].t];
				tmp[f[l].t]=min(tmp[f[l].t],(LL)f[l].c);
				bsum[i]=bsum[i]+tmp[f[l].t];
			}
			l--;
		}
	}
	ans=inf;
	for (int i=1;i<=f[m-1].d;i++){
		if (i+k>f[m-1].d) break;
		ans=min(ans,gsum[i]+bsum[i+k]);
	}
	if (ans==inf) printf("-1\n");
	else printf("%lld\n",ans);
}