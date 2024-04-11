#include<bits/stdc++.h> 
using namespace std;
int T,i,n,l,r,tot,gs;
struct mjj{int x,y,t;}a[200010];
bool cmp(mjj a,mjj b){return a.x<b.x;}
int main(){
	scanf("%d%d",&n,&T);
	for(i=1;i<=n;i++)scanf("%d%d",&a[i].y,&a[i].x),a[i].t=i;
	sort(a+1,a+n+1,cmp);
	for(l=0,r=n;l<r;){
		int mid=l+r+1>>1;
		tot=gs=0;
		for(i=1;i<=n;i++)
		if(a[i].y>=mid){
			if(tot+a[i].x>T)break;
			else tot+=a[i].x,gs++;
		}
		if(gs>=mid)l=mid;else r=mid-1;
	}
	gs=0;
	printf("%d\n%d\n",l,l);
	for(i=1;i<=n&&gs<l;i++)
		if(a[i].y>=l)
			printf("%d ",a[i].t),gs++;
	puts("");
}