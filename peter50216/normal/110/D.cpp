#include<stdio.h>
#include<algorithm>
using namespace std;
int num[10000],nc=0;
inline void dfs(int np){
    num[nc++]=np;
    if(np>100000000)return;
    dfs(np*10+4);
    dfs(np*10+7);
}
inline long long f(int l,int r,int x,int y){
    l=max(l,x);
    r=min(r,y);
    if(r<l)return 0;
    return r-l+1ll;
}
int main(){
    dfs(0);
    sort(num,num+nc);
    num[nc++]=1000000002;
    int pl,pr,vl,vr,k,i;
    scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
    long long ans=0;
    for(i=1;i+k-1<nc-1;i++){
	int lmi,lma,rmi,rma;
	lmi=num[i-1]+1;
	lma=num[i];
	rmi=num[i+k-1];
	rma=num[i+k]-1;
	long long k1=f(lmi,lma,pl,pr)*f(rmi,rma,vl,vr);
	long long k2=f(lmi,lma,vl,vr)*f(rmi,rma,pl,pr);
	ans+=k1+k2;
	if(k1&&k2&&k==1)ans--;
    }
    printf("%.12lf\n",(double)ans/(vr-vl+1ll)/(pr-pl+1ll));
}