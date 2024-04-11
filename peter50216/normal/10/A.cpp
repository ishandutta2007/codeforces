#include<stdio.h>
int main(){
    int n,p1,p2,p3,t1,t2,i,j;
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
    int rr=-1;
    int ans=0;
    while(n--){
	int l,r;
	scanf("%d%d",&l,&r);
	ans+=(r-l)*p1;
	if(rr!=-1){
	    int d=l-rr;
	    if(d<t1)ans+=d*p1;
	    else if(d<t1+t2)ans+=t1*p1+(d-t1)*p2;
	    else ans+=t1*p1+t2*p2+(d-t1-t2)*p3;
	}
	rr=r;
    }
    printf("%d\n",ans);
}