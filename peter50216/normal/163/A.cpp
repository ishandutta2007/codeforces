#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
char a[5010],b[5010];
int al,bl;
int dp[5010][5010];
const int mod=1000000007;
inline int ADD(int a,int b){
    a+=b;
    if(a>=mod)a-=mod;
    return a;
}
int ps[5010][26];
int main(){
    scanf("%s%s",a,b);
    al=strlen(a);bl=strlen(b);
    int i,j,k;
    for(i=0;i<26;i++)ps[0][i]=-1;
    for(i=1;i<=bl;i++){
        for(j=0;j<26;j++)ps[i][j]=ps[i-1][j];
        ps[i][b[i-1]-'a']=i-1;
    }
    int c=0;
    int ans=0;
    for(i=0;i<bl;i++){
        if(b[i]==a[0]){
            dp[0][i]=1;
        }else dp[0][i]=0;
        ans=ADD(ans,dp[0][i]);
        if(ps[i][b[i]-'a']!=-1)dp[0][i]=ADD(dp[0][i],dp[0][ps[i][b[i]-'a']]);
    }
    for(i=1;i<al;i++){
        for(j=0;j<bl;j++){
            if(b[j]==a[i]){
                dp[i][j]=1;
                if(ps[j][a[i-1]-'a']!=-1){
                    dp[i][j]=ADD(dp[i][j],dp[i-1][ps[j][a[i-1]-'a']]);
                }
            }else dp[i][j]=0;
            ans=ADD(ans,dp[i][j]);
            if(ps[j][b[j]-'a']!=-1)dp[i][j]=ADD(dp[i][j],dp[i][ps[j][b[j]-'a']]);
        }
    }
    printf("%d\n",ans);
}