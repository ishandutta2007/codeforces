#include<stdio.h>
int n;
int log2[17000000];
int x[25],y[25];
int dp[17000000];
int pre[17000000];
inline void printp(int np){
    if(np==0)return;
    int x=pre[np];
    while(x){
	printf(" %d",log2[x&-x]+1);
	x-=x&-x;
    }
    printf(" 0");
    printp(np-pre[np]);
}
inline int dis(int a,int b){
    if(a==-1)return x[b]*x[b]+y[b]*y[b];
    return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);
}
inline int dpf(int np){
    if(np==0)return 0;
    if(dp[np])return dp[np];
    int nn=np&-np;
    dp[np]=dpf(np-nn)+2*dis(-1,log2[nn]);
    pre[np]=nn;
    int nnp=np-nn;
    while(nnp){
	int ld=nnp&-nnp;
	int r=dpf(np-nn-ld)+dis(-1,log2[nn])+dis(-1,log2[ld])+dis(log2[nn],log2[ld]);
	if(r<dp[np]){
	    dp[np]=r;
	    pre[np]=nn+ld;
	}
	nnp-=ld;
    }
    return dp[np];
}
int main(){
    int sx,sy,i;
    for(i=0;i<24;i++)log2[1<<i]=i;
    scanf("%d%d",&sx,&sy);
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d%d",&x[i],&y[i]);
	x[i]-=sx;y[i]-=sy;
    }
    printf("%d\n",dpf((1<<n)-1));
    printf("0");
    printp((1<<n)-1);
    puts("");
}