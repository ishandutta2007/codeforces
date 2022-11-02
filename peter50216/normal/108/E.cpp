#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> ed[20];
vector<int> red[20];
int edb[20];
int redb[20];
int ans[20];
int n,m;
long long y;
bool vis[20];
bool hasc=0;
inline void dfs(int np,int to){
    if(vis[np]){
	if(np==to)hasc=1;
	return;
    }
    vis[np]=1;
    int i;
    for(i=0;i<ed[np].size();i++)dfs(ed[np][i],to);
}
inline bool findcyc(){
    int i;
    for(i=0;i<n;i++){
	memset(vis,0,sizeof(vis));
	dfs(i,i);
    }
    return hasc;
}
long long dp[70000];
int log2[70000];
int used[20];
int big[20];
int small[20];
inline long long dpf(int sp,int st){
    if(dp[sp]!=-1)return dp[sp];
    if(sp==0)return dp[sp]=1;
    int rr=st&-st;
    int r=log2[rr];
    int ssp=sp,i;
    dp[sp]=0;
    while(ssp){
	int e=ssp&-ssp;
	int ee=log2[e];
	ssp-=e;
	if(sp&edb[ee])continue;
	if(big[r]&edb[ee])continue;
	if(small[r]&redb[ee])continue;
	dp[sp]+=dpf(sp-e,st-rr);
    }
    //printf("r=%d big=%d small=%d %d %d %d\n",r,big[r],small[r],sp,st,dp[sp]);
    return dp[sp];
}
inline long long count(){
    memset(used,-1,sizeof(used));
    int i,j;
    for(i=0;i<n;i++){
	if(ans[i]==-1)break;
	if(used[ans[i]]!=-1)return 0;
	used[ans[i]]=i;
    }
    for(i=0;i<n;i++){
	if(ans[i]==-1)break;
	for(j=0;j<ed[i].size();j++){
	    int y=ed[i][j];
	    if(ans[y]!=-1&&ans[y]>ans[i])return 0;
	}
    }
    memset(big,0,sizeof(big));
    memset(small,0,sizeof(small));
    for(i=0;i<n;i++){
	if(ans[i]==-1)break;
	for(j=ans[i]+1;j<=n;j++)small[j]|=(1<<i);
	for(j=0;j<ans[i];j++)big[j]|=(1<<i);
    }
    int st=(1<<n)-1;
    int cnt=(1<<n)-1;
    for(i=0;i<n;i++){
	if(ans[i]==-1)break;
	st-=(1<<ans[i]);
	cnt-=(1<<i);
    }
    memset(dp,-1,sizeof(dp));
    return dpf(cnt,st);
}
inline bool solve(){
    if(findcyc())return 0;
    memset(ans,-1,sizeof(ans));
    long long r=count();
    //printf("r=%lld\n",r);
    if(r<y)return 0;
    long long nc=0;
    int i,j;
    for(i=0;i<n;i++){
	//printf("i=%d\n",i);
	for(j=0;j<n;j++){
	    //printf("  j=%d\n",j);
	    ans[i]=j;
	    long long r=count();
	    if(nc+r>=y)break;
	    else nc+=r;
	}
    }
    return 1;
}
int main(){
    int i;
    for(i=0;i<16;i++)log2[1<<i]=i;
    scanf("%d%I64d%d",&n,&y,&m);
    y-=2000;
    for(i=0;i<m;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	a--;b--;
	ed[b].push_back(a);
	edb[b]|=(1<<a);
	red[a].push_back(b);
	redb[a]|=(1<<b);
    }
    if(solve()){
	for(i=0;i<n;i++)printf("%d%c",ans[i]+1,(i==n-1)?'\n':' ');
    }else puts("The times have changed");
}