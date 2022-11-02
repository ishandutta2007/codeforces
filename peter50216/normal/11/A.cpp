#include<stdio.h>
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    int ans=0;
    int l=0;
    while(n--){
	int x;
	scanf("%d",&x);
	if(l&&x<=l){
	    int dd=(l-x+d)/d;
	    ans+=dd;
	    x+=dd*d;
	}
	l=x;
    }
    printf("%d\n",ans);
}