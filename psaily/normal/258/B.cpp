#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int mod=1e9+7;

int m;
ll ans;
int cnt[20];
int bit[20],pos;

int dp[20][20][2];

int dfs(int pos,int sta,bool limit){
	if(sta<0)return 0;
	if(pos==-1){
		if(sta==0)return 1;
		return 0;
	}
	if(~dp[pos][sta][limit])return dp[pos][sta][limit];
	int &res=dp[pos][sta][limit];res=0;
	int up=limit?bit[pos]:9;
	for(int i=0;i<=up;i++)res+=dfs(pos-1,sta-(i==4||i==7),limit&&i==up);
	return res;
}

void find(int choose,int mx,int part,ll res){
	if(choose>=mx)return;
	if(part==7){
		ans+=res;
		ans%=mod;
		return;
	}
	for(int i=0;i<=pos;i++)if(cnt[i]){
		cnt[i]--;
		find(choose+i,mx,part+1,1ll*res*(cnt[i]+1)%mod);
		cnt[i]++;
	}
}

void solve(int x){
	memset(dp,-1,sizeof(dp));
	pos=0;
	while(x){
		bit[pos++]=x%10;
		x/=10;
	}
	for(int i=0;i<=pos;i++)cnt[i]=dfs(pos-1,i,1);
	cnt[0]--;
	for(int i=1;i<=pos;i++)if(cnt[i])find(0,i,1,cnt[i]);
}

int main(){
	scanf("%d",&m);
	solve(m);
	printf("%lld\n",ans);
	return 0;
}