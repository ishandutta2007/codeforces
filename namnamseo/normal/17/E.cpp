#include <cstdio>

char buf[2000010];
char s[4000010];
int dp[4000010];
int n;

int max(int a,int b){ return a>b?a:b; }
int min(int a,int b){ return a<b?a:b; }

int lh[4000010];
int rh[4000010];

long long ls[2000010];

int main()
{
    scanf("%*d");
    scanf("%s",buf);
    int i;
    s[0]='#';
    for(i=0;buf[i];++i) s[2*i+1]=buf[i], s[2*i+2]='#';
    int c=0;
    int j;
    for(n=0;s[n];++n);
    for(i=1;i<n;++i){
        j=2*c-i;
        if(j>=0) dp[i]=max(0,min(dp[j],j-(c-dp[c])));
        for(;i-dp[i]-1>=0 && i+dp[i]+1<n && s[i-dp[i]-1]==s[i+dp[i]+1];) ++dp[i];
        if(c+dp[c]<i+dp[i]) c=i;
    }
    for(i=0;i<n;++i){
        ++lh[i-dp[i]];
        --lh[i+1];
        ++rh[i];
        --rh[i+dp[i]+1];
    }
    for(i=1;i<n;++i) lh[i]+=lh[i-1], rh[i]+=rh[i-1];
    for(i=n/2-1;0<=i;--i) ls[i]=(ls[i+1]+lh[i*2+1])%51123987;
    long long ans=0, sum=0;
    int hn=n/2;
    sum=ls[0];
    for(i=0;i<hn;++i){
        ans+=1LL*rh[2*i+1]*ls[i+1]%51123987;
        ans%=51123987;
    }
    sum%=51123987;
    printf("%I64d\n",(sum*(sum-1)/2-ans)%51123987);
    return 0;
}