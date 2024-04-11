#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int in[160];
int dp[160][160][160];
char tt[160];
inline int dpf(int x,int y,int o){
    int i;
    if(dp[x][y][o]!=-1) return dp[x][y][o];
    if(x>y)return dp[x][y][o]=(in[o*2]==-1?-514:in[o*2]);
    if(x==y){
        if(in[1+o*2]!=-1)dp[x][y][o]=in[1+o*2];
        if(in[1]!=-1&&in[o*2]!=-1){
            int r=in[1]+in[o*2];
            if(r>dp[x][y][o])dp[x][y][o]=r;
        }
        return dp[x][y][o]==-1?dp[x][y][o]=-514:dp[x][y][o];
    }else{
        if(tt[x]==tt[y]){
            dp[x][y][o]=dpf(x+1,y-1,o+1);
            if(o&&in[o*2]!=-1){
                int r=dpf(x,y,0);
                if(r!=-514)r+=in[o*2];
                if(r>dp[x][y][o])dp[x][y][o]=r;
            }
        }
        if(in[o*2]!=-1){
            for(i=x;i<y;i++){
                int r1=dpf(x,i,0),r2=dpf(i+1,y,0);
                if(r1!=-514&&r2!=-514){
                    int r=r1+r2+in[o*2];
                    if(r>dp[x][y][o])dp[x][y][o]=r;
                }
            }
        }
        for(i=x;i<y;i++){
            int r1=dpf(x,i,0),r2=dpf(i+1,y,o);
            if(r1!=-514&&r2!=-514){
                int r=r1+r2;
                if(r>dp[x][y][o])dp[x][y][o]=r;
            }
            r1=dpf(x,i,o),r2=dpf(i+1,y,0);
            if(r1!=-514&&r2!=-514){
                int r=r1+r2;
                if(r>dp[x][y][o])dp[x][y][o]=r;
            }
        }
        if(in[o*2+1]!=-1){
            int r=dpf(x+1,y,0);
            if(r!=-514)r+=in[o*2+1];
            if(r>dp[x][y][o])dp[x][y][o]=r;
            r=dpf(x,y-1,0);
            if(r!=-514)r+=in[o*2+1];
            if(r>dp[x][y][o])dp[x][y][o]=r;
            for(i=x+1;i<y;i++){
                int r1=dpf(x,i-1,0),r2=dpf(i+1,y,0);
                if(r1!=-514&&r2!=-514){
                    int r=r1+r2+in[o*2+1];
                    if(r>dp[x][y][o])dp[x][y][o]=r;
                }
            }
        }
        return dp[x][y][o]==-1?dp[x][y][o]=-514:dp[x][y][o];
    }
}
int dd[200];
int main(){
    int n,i,j,k,q,w,e;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&in[i]);
    scanf("%s",tt);
    memset(dp,-1,sizeof(dp));
    dd[0]=0;
    for(i=1;i<=n;i++){
        dd[i]=dd[i-1];
        for(j=0;j<i;j++){
            int r=dpf(j,i-1,0);
            if(r!=-514)dd[i]=max(dd[i],dd[j]+r);
        }
    }
    printf("%d\n",dd[n]);
}