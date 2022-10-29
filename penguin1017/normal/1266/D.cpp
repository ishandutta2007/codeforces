#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=3e5+9;
ll money[N],cost[N];
pii ans[N];
struct node{
	ll c;
	int id;
};
node ans1[N],ans2[N];
bool cmp(node a,node b){
	return a.c>b.c;
}
int main(){
	int n,m,cnt1=0,cnt2=0;
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		money[u]+=d;
		money[v]-=d;
	}
	rep(i,1,n+1){
		if(money[i]>0)ans1[cnt1++]=(node){money[i],i};
		else ans2[cnt2++]=(node){-money[i],i};
	}
	sort(ans1,ans1+cnt1,cmp);
	sort(ans2,ans2+cnt2,cmp);
	int p1=0,p2=0,cnt=0;
	while(p1<cnt1&&p2<cnt2){
		ll mini=min(ans1[p1].c,ans2[p2].c);
		++cnt;
		cost[cnt]=mini;
		ans[cnt]={ans1[p1].id,ans2[p2].id};
		ans1[p1].c-=mini;
		ans2[p2].c-=mini;
		if(!ans1[p1].c)++p1;
		if(!ans2[p2].c)++p2;
	}
	printf("%d\n",cnt);
	rep(i,1,cnt+1){
		printf("%d %d %lld\n",ans[i].fi,ans[i].se,cost[i]);
	}
}