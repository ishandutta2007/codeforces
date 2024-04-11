#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int dp[101000];
int x[101000],t[101000];
int id[101000];
long long v1[101000],v2[101000];
long long v;
int tmt[101000];
inline bool cmp(int a,int b){
    return v1[a]==v1[b]?v2[a]>v2[b]:v1[a]>v1[b];
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d%d",&x[i],&t[i]);
	id[i]=i;
    }
    scanf("%I64d",&v);
    for(i=0;i<n;i++){
	v1[i]=v*t[i]-x[i];
	v2[i]=v*t[i]+x[i];
    }
    sort(id,id+n,cmp);
    //puts("!");
    dp[0]=INT_MAX;
    int tt=0;
    for(i=0;i<n;i++){
	int l=0,r=tt;
	while(l<r){
	    int m=(l+r+1)/2;
	    if(dp[m]>=v2[id[i]])l=m;
	    else r=m-1;
	}
	dp[l+1]=v2[id[i]];
	tmt[id[i]]=l+1;
	if(tt==l)tt=l+1;
    }
    int ans=0;
    for(i=0;i<n;i++){
	if((x[i]>0?x[i]:-x[i])<=t[i]*v){
	    ans=max(ans,tmt[i]);
	}
    }
    printf("%d %d\n",ans,tt);
}