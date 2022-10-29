#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

ll m;
int k;

int num[65],pos;
bool vis[66][66][2];
ll dp[66][66][2];

ll dfs(int pos,int sta,bool limit){
	if(sta<0)return 0;
	if(pos==-1){
		if(!sta)return 1;
		else return 0;
	}
	if(vis[pos][sta][limit])return dp[pos][sta][limit];
	int up=limit?num[pos]:1;
	vis[pos][sta][limit]=1;
	ll &res=dp[pos][sta][limit];
	res=0;
	for(int i=0;i<=up;i++)res+=dfs(pos-1,sta-(i==1),limit&&i==up);
	return res;
} 

ll solve(ll x){//x 
	memset(vis,0,sizeof(vis));
	pos=0;
	while(x){
		num[pos++]=x&1;
		x>>=1;
	}
	//for(int i=0;i<pos;i++)printf("%d ",num[i]);puts(""); 
	return dfs(pos-1,k,1);
}

ll check(ll mid){return solve(mid*2)-solve(mid);}

int main(){
	scanf("%lld%d",&m,&k);
	ll l=1,r=1e18,res=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll chk=check(mid);
		//bug(mid),debug(chk);
		if(chk>=m)res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",res);
//	for(int i=1;i<=n;i++){
//		memset(cnt,0,sizeof(cnt));
//		for(int j=i+1;j<=i*i;j++){
//			int ct=0;
//			for(int k=0;k<20;k++)if(j>>k&1)ct++;
//			cnt[ct]++;
//		}
//		printf("%2d ",i);;for(int j=0;j<15;j++)printf("%4d ",cnt[j]);puts("");
//	}
	return 0;
}