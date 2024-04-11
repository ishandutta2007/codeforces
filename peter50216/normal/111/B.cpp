#include<stdio.h>
int pd[100000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
	int x,y;
	scanf("%d%d",&x,&y);
	int ans=0;
	for(j=1;j*j<=x;j++){
	    if(x%j==0){
		int d;
		d=j;
		if(pd[d]<i-y)ans++;
		pd[d]=i;
		if(x!=j*j){
		    d=x/j;
		    if(pd[d]<i-y)ans++;
		    pd[d]=i;
		}
	    }
	}
	printf("%d\n",ans);
    }
}