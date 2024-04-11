#include<bits/stdc++.h>
#define mo 1000000007
int dp[6][1<<20],ans,n;
char ch[76];
int main(){
    scanf("%d\n",&n);
    for (int i=0;i<n;i++) ch[i]=getchar();
    for (int i=0;i<6;i++) dp[i][0]=1;
    for (int i=0;i<n;i++){
        int l=i,tmp=0;
        if (i>=5){
            for (int j=0;j<(1<<20);j++){
                if (ch[i-5]=='0') dp[(i+1)%6][j]=(dp[(i+1)%6][j]+dp[i%6][j])%mo;
                dp[i%6][j]=0;
            }
        }
        dp[i%6][0]=1;
        while ((l>=0)&&((i-l)<5)){
            tmp=tmp+((ch[l]-'0')<<(i-l));
            if ((tmp>0)&&(tmp<21)){
                for (int j=(1<<20)-1-(1<<(tmp-1));j;j=(j-1)&((1<<20)-1-(1<<(tmp-1)))){
                    dp[i%6][j|(1<<(tmp-1))]=(dp[i%6][j|(1<<(tmp-1))]+dp[(l+5)%6][j])%mo;
                    dp[i%6][j|(1<<(tmp-1))]=(dp[i%6][j|(1<<(tmp-1))]+dp[(l+5)%6][j|(1<<(tmp-1))])%mo;
                }
                dp[i%6][1<<(tmp-1)]=(dp[i%6][1<<(tmp-1)]+dp[(l+5)%6][1<<(tmp-1)])%mo;
                dp[i%6][1<<(tmp-1)]=(dp[i%6][1<<(tmp-1)]+dp[(l+5)%6][0])%mo;
            }
            l--;
        }
        tmp=0;
        for (int j=0;j<20;j++){
            tmp+=1<<j;
            ans=(ans+dp[i%6][tmp])%mo;
        }
    }
    printf("%d\n",ans);
}