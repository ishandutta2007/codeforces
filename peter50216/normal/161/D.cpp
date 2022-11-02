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
int n,k;
int cnt[50010][510];
vector<int> ed[50010];
int pre[50010];
inline void dfs(int np,int p){
    pre[np]=p;
    int i;
    for(i=0;i<ed[np].size();i++){
        int y=ed[np][i];
        if(y==p)continue;
        dfs(y,np);
    }
    cnt[np][0]=1;
    if(p!=-1){
        for(i=0;i<k;i++){
            cnt[p][i+1]+=cnt[np][i];
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    int i,j;
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    if(k==1){
        printf("%d\n",n-1);
        return 0;
    }
    dfs(0,-1);
    long long ans=0;
    for(i=0;i<n;i++){
        if(pre[i]==-1)continue;
        ans+=cnt[i][k-1]*2ll;
        for(j=0;j<=k-2;j++){
            ans+=((long long)cnt[i][j])*(cnt[pre[i]][k-1-j]-cnt[i][k-2-j]);
        }
    }
    printf("%I64d\n",ans/2);
}