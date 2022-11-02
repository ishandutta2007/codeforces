#include<bits/stdc++.h>
using namespace std;
int n,k,dp[2020][2020],pre[2020][2020];
char ch[2020][2020];
void get(int x,int y){
    if (x==0&&y==0){
        if (dp[0][0]==k) printf("%c",ch[0][0]);
        else printf("a");
        return;
    }
    if (pre[x][y]==0){
        get(x-1,y);
        if (dp[x][y]==dp[x-1][y]) printf("%c",ch[x][y]);
        else printf("a");
    }
    else{
        get(x,y-1);
        if (dp[x][y]==dp[x][y-1]) printf("%c",ch[x][y]);
        else printf("a");
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%s",ch[i]);
    memset(dp,0xff,sizeof(dp));
    dp[0][0]=k;
    if (ch[0][0]!='a') dp[0][0]=max(0,k-1); 
    for (int i=0;i<2*n-2;i++){
        int mi=27;
        for (int j=0;j<n;j++)
        if (i-j<n&&i-j>=0&&dp[j][i-j]!=-1){
            if (j<n-1) mi=min(mi,ch[j+1][i-j]-'a');
            if (i-j<n-1) mi=min(mi,ch[j][i-j+1]-'a');
            if (dp[j][i-j]>0) mi=0;
        }
        for (int j=0;j<n;j++)
        if (i-j<n&&i-j>=0&&dp[j][i-j]!=-1){
            if (j<n-1){
                int tmp=dp[j][i-j]-(ch[j+1][i-j]-'a'!=mi);
                if (dp[j+1][i-j]<tmp){
                    dp[j+1][i-j]=tmp;
                    pre[j+1][i-j]=0;
                }
            }
            if (i-j<n-1){
                int tmp=dp[j][i-j]-(ch[j][i-j+1]-'a'!=mi);
                if (dp[j][i-j+1]<tmp){
                    dp[j][i-j+1]=tmp;
                    pre[j][i-j+1]=1;
                }
            }
        }
    }
    get(n-1,n-1);
}