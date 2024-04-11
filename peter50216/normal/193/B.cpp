#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int n,u,r;
long long ai[50],bi[50],ki[50],pi[50];
int cc[50][50];
long long ans;
inline void dfs(int np,int p){
    int i;
    if((u-np)%2==0){
        long long rr=0;
        for(i=0;i<n;i++){
            rr+=cc[np][i]*(long long)ki[i];
        }
        ans=max(ans,rr);
        if(np==u)return;
    }
    for(i=0;i<n;i++){
        cc[np+1][i]=cc[np][pi[i]]+r;
    }
    dfs(np+1,0);
    if(!p){
        for(i=0;i<n;i++){
            cc[np+1][i]=cc[np][i]^bi[i];
        }
        dfs(np+1,1);
    }
}
int main(){
    int i;
    scanf("%d%d%d",&n,&u,&r);
    for(i=0;i<n;i++)scanf("%I64d",&ai[i]);
    for(i=0;i<n;i++)scanf("%I64d",&bi[i]);
    for(i=0;i<n;i++)scanf("%I64d",&ki[i]);
    for(i=0;i<n;i++){
        scanf("%I64d",&pi[i]);
        pi[i]--;
    }
    for(i=0;i<n;i++)cc[0][i]=ai[i];
    ans=-1000000000000000ll;
    dfs(0,0);
    printf("%I64d\n",ans);
}