#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
using namespace std;
int n;
struct P{
     int x,y;
}po[2525],v[5050];
LL ans;
int Q(P a){
  if(a.x>0&&a.y>=0) return 1;
  if(a.x<=0&&a.y>0) return 2;
  if(a.x<0&&a.y<=0) return 3;
  if(a.x>=0&&a.y<0) return 4;
}
int cmp(P x,P y){
	if (Q(x)==Q(y))
		return 1ll*x.x*y.y-1ll*x.y*y.x>=0;
	else return Q(x)<Q(y);
}
LL f(int x){
	if (x>=3) return 1ll*x*(x-1)*(x-2)/3/2/1;
	return 0;
}
int main(){
	//freopen("E.in","r",stdin);
	scanf("%d",&n);
	ans=5ll*n*(n-1)*(n-2)*(n-3)*(n-4)/5/4/3/2;
	for (int i=0;i<n;i++) scanf("%d%d",&po[i].x,&po[i].y);
	for (int i=0;i<n;i++){
		int cnt=0;
		for (int j=0;j<n;j++)
		if (i!=j){
			v[cnt].x=po[j].x-po[i].x;
			v[cnt].y=po[j].y-po[i].y;
			cnt++;
		}
		sort(v,v+cnt,cmp);
		//for (int j=0;j<cnt;j++) printf("%d %d\n",v[j].x,v[j].y);
		//printf("\n");
		for (int j=0;j<cnt;j++) v[cnt+j]=v[j];
		int tail=0;
		for (int j=0;j<cnt;j++){
			while (tail<j+cnt&&1ll*v[j].x*v[tail].y-1ll*v[j].y*v[tail].x>=0) tail++;
			//printf("%d %d\n",j,tail);
			ans-=f(tail-j-1);
		}
		//printf("\n");
	}
	printf("%lld\n",ans);
}