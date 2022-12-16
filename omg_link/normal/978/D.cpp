#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MN 100000
#define INF 0x7fffffff
int n,d,tans,ans=INF;
int a[MN+5],b[MN+5];
bool f;
void over(int ans){
	printf("%d",ans);
	exit(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1||n==2)over(0);
	for(int c1=-1;c1<=1;c1++)
		for(int c2=-1;c2<=1;c2++){
			f=true;
			tans=(c1!=0)+(c2!=0);
			b[1]=a[1]+c1;
			b[2]=a[2]+c2;
			d=b[2]-b[1];
			for(int i=3;i<=n;i++){
				b[i]=b[i-1]+d;
				if(std::abs(b[i]-a[i])>1){
					f=false; break;
				}
				tans+=(b[i]!=a[i]);
			}
			if(!f)continue;
			ans=std::min(ans,tans);
		}
	printf("%d",ans==INF?-1:ans);
}