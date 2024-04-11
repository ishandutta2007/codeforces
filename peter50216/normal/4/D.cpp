#include<stdio.h>
#include<algorithm>
using namespace std;
struct XD{
    int a,b,id;
    XD(int aa=0,int bb=0,int ii=0):a(aa),b(bb),id(ii){}
    bool operator<(const XD& x)const{
	return a==x.a?b>x.b:a<x.a;
    }
};
XD in[5100];
int dp[5100];
int pre[5100];
int ans[5100],ac;
int main(){
    int q,w,h,n=0,i;
    scanf("%d%d%d",&q,&w,&h);
    for(i=0;i<q;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<=w||b<=h)continue;
	in[n++]=XD(a,b,i);
    }
    if(n==0){
	puts("0");
	return 0;
    }
    sort(in,in+n);
    in[n].b=0;
    dp[0]=n;
    int x=0;
    for(i=0;i<n;i++){
	int l=0,r=x;
	while(l<r){
	    int m=(l+r+1)/2;
	    if(in[dp[m]].b<in[i].b)l=m;
	    else r=m-1;
	}
	pre[i]=dp[l];
	dp[l+1]=i;
	if(l==x)x++;
    }
    printf("%d\n",x);
    int np=dp[x];
    ac=0;
    while(np!=n){
	ans[ac++]=in[np].id;
	np=pre[np];
    }
    while(ac--)printf("%d%c",ans[ac]+1,ac?' ':'\n');
}