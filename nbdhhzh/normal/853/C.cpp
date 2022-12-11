#include<bits/stdc++.h>
#define N 410000
using namespace std;
int n,i,j,f[N],b[N],l,d,r,u,cnt,m;
long long ans[N];
struct mjj{int x,y,z,t;}a[N*4];
void add(int x){for(;x<=n;x+=x&-x)b[x]++;}
int ask(int x){int y=0;for(;x;x-=x&-x)y+=b[x];return y;}
bool cmp(mjj a,mjj b){return a.x<b.x;}
long long ct(int a){return 1ll*a*(a-1)/2;}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&f[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&l,&d,&r,&u);
		ans[i]=ct(l-1)+ct(d-1)+ct(n-r)+ct(n-u);
		a[++cnt].x=l;a[cnt].y=d;a[cnt].z=0;a[cnt].t=i; 
		a[++cnt].x=l;a[cnt].y=u;a[cnt].z=1;a[cnt].t=i;
		a[++cnt].x=r;a[cnt].y=d;a[cnt].z=2;a[cnt].t=i;
		a[++cnt].x=r;a[cnt].y=u;a[cnt].z=3;a[cnt].t=i;
	}
	sort(a+1,a+cnt+1,cmp);
	memset(b,0,sizeof(b));
	for(i=j=1;i<=n;i++){
		for(;a[j].x==i;j++)
			if(a[j].z==0)ans[a[j].t]-=ct(ask(a[j].y-1));
			else if(a[j].z==1)ans[a[j].t]-=ct(i-1-ask(a[j].y));
		add(f[i]);
	}
	j=cnt;
	memset(b,0,sizeof(b));
	for(i=n;i>=1;i--){
		for(;a[j].x==i;j--)
			if(a[j].z==2)ans[a[j].t]-=ct(ask(a[j].y-1));
			else if(a[j].z==3)ans[a[j].t]-=ct(n-i-ask(a[j].y));
		add(f[i]);
	}
	for(i=1;i<=m;i++)printf("%I64d\n",ct(n)-ans[i]);
}