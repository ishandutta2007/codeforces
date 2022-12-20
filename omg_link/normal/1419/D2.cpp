#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,dl,a[MN+5],b[MN+5];

int gn(){
	static int r=1;
	if(r<=n) return r++;
	else return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n,std::greater<int>());
	a[0] = -1;
	for(int i=1;i<=n;i+=2)
		b[i] = a[gn()];
	for(int i=2;i<=n;i+=2){
		while(1){
			int t = a[gn()];
			if(t<b[i+1]){
				b[i] = t;
				break;
			}else{
				dl = t;
			}
		}
		if(b[i]==-1) b[i] = dl;
	}
	b[0] = b[n+1] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++)
		if(b[i]<b[i-1]&&b[i]<b[i+1]) ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
}