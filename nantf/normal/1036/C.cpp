#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll l,r,dp[20][10][5],bit[20],blen;
ll dfs(int pos,int num,int cnt,bool zero,bool limit){
	if(!pos) return 1;
	if(~dp[pos][num][cnt] && !zero && !limit) return dp[pos][num][cnt];
	ll sum=0;
	if(cnt==3) sum+=dfs(pos-1,0,cnt,zero,limit && !bit[pos]);
	else{
		int upr=limit?bit[pos]:9;
		for(int i=0;i<=upr;i++) sum+=dfs(pos-1,i,cnt+(!!i),zero && !i,limit && i==upr);
	}
	if(!zero && !limit) dp[pos][num][cnt]=sum;
	return sum;
}
ll solve(ll x){
	memset(dp,-1,sizeof(dp));
	blen=0;
	while(x) bit[++blen]=x%10,x/=10;
	return dfs(blen,0,0,true,true);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",solve(r)-solve(l-1));
	}
}