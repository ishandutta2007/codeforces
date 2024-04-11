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
int dp[N],dp2[N];
struct node{
	int t,a,b;
}p[120];
bool cmp(node a,node b){
	return a.t<b.t;	
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d%d",&n,&dp[0]);
		rep(i,1,n+1)scanf("%d%d%d",&p[i].t,&p[i].a,&p[i].b);
		sort(p+1,p+1+n,cmp);
		int T=0,flag=1;
		dp2[0]=dp[0];
		rep(i,1,n+1){
			dp[i]=dp[i-1]+p[i].t-T;
			dp2[i]=dp2[i-1]-p[i].t+T;
			if(dp2[i]>p[i].b||dp[i]<p[i].a){
				flag=0;
				break;
			}
			else{
				dp2[i]=max(dp2[i],p[i].a);
				dp[i]=min(dp[i],p[i].b);
			}
			T=p[i].t;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
}