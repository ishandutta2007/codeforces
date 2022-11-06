#include <cstdio>

int dp[2100];
int treesum[2100];
int n;

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int rangeMax(int a,int b){
    a+=(1<<n); b+=(1<<n);
    int ret=2e8;
    while(a<=b){
        if(a==b){
            ret=min(ret,dp[a]);
            break;
        }
        if(a&1){ ret=min(ret,dp[a]); ++a; }
        if((b+1)&1){ ret=min(ret,dp[b]); --b; }
        a/=2; b/=2;
    }
    return ret;
}
int ans;
void work(int pos,int left,int right){
    int maxval=rangeMax(left,right)-treesum[pos/2];
    ans+=maxval;
    treesum[pos]=treesum[pos/2]+maxval;
    if(left==right){
        return;
    }
    work(pos*2,left,(left+right)/2);
    work(pos*2+1,(left+right)/2+1,right);
}

int main()
{
    scanf("%d",&n);
    int i,t=(1<<(n+1));
    int buf;
    int maxval=-1, sum=0;
    for(i=2;i<t;++i) scanf("%d",&buf),dp[i]=dp[i/2]+buf, maxval=max(maxval,dp[i]);
    for(i=t/2;i<t;++i) dp[i]=maxval-dp[i];
    t/=2;
    for(i=t-1;1<=i;--i) dp[i]=min(dp[i*2],dp[i*2+1]);
    work(1,0,(1<<n)-1);
    printf("%d\n",ans);
    return 0;
}