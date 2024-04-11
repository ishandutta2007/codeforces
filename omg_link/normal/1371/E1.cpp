#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,p,a[MN+5];

int dc=0;
struct data{
	int a,count,pre;
	data(){a=0;count=0;pre=0;}
}d[MN+5];

bool check(int x){
	int r=0;
	while(r<=n&&x>=a[r]) r++;
	for(int i=1;i<=n;i++){
		if(r-i>=p) return false;
		x++;
		while(r<=n&&x>=a[r]) r++;
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i] != d[dc].a){
			dc++;
			d[dc].a = a[i];
		}
		d[dc].count++;
		d[dc].pre = d[dc-1].pre + d[dc].count;
	}
	//find min x
	int minx = 1;
	for(int i=1;i<=dc;i++){
		minx = std::max(minx,d[i].a-d[i-1].pre);
	}
	//dichotomy er fen fa
	int l=minx,r=a[n],mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}//return r
	printf("%d\n",r-minx+1);
	for(int i=minx;i<=r;i++)
		printf("%d ",i);
}