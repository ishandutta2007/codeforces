#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
int cost[1441],t[N];
int main(){
	int n,last=20;
	scanf("%d",&n);
	scanf("%d",&t[0]);
	cost[1]=20,cost[90]=50,cost[1440]=120;
	rep(i,2,90)cost[i]=50;
	rep(i,91,1440)cost[i]=120;
	printf("%d\n",20);
	rep(i,1,n){
		scanf("%d",&t[i]);
		int ans=INT_MAX,mini=cost[1];
		int id=t[i]-t[i-1]+1,pos=1;
		for(;id<=1440;++id,++pos)cost[pos]=cost[id];
		for(;pos<=1440;++pos)cost[pos]=INT_MAX;
		cost[1]=min(cost[1],mini+20);
		cost[90]=min(cost[90],mini+50);
		cost[1440]=min(cost[1440],mini+120);
		per(i,1,1440)cost[i]=min(cost[i],cost[i+1]);
		ans=cost[1];
		printf("%d\n",ans-last);
		last=ans;
	}
}