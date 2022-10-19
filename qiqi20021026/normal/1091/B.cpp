#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int a,b,c,d,n,x,y;

int main(){
	scanf("%d",&n);
	a=b=INF;
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if (x<a){a=x; b=y;}
		if (x==a) b=min(b,y);
	}
	c=d=-INF;
	for (int i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		if (x>c){c=x; d=y;}
		if (x==c) d=max(d,y);
	}
	printf("%d %d\n",a+c,b+d);
	
	return 0;
}