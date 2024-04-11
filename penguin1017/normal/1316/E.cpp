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
#define all(x) x.begin(),x.end()
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
ll dp[N][1<<7];
int s[N][1<<7],st[N],Log[1<<7];
struct node{
	int v,id;
}a[N];
bool cmp(node a,node b){
	return a.v>b.v;
}
void upd(ll &a,ll b){
	if(a<b)a=b;
}
int main(){
	int n,p,k;
	rep(i,1,N)st[i]=st[i>>1]+(i&1);
	rep(i,0,7)Log[1<<i]=i;
	scanf("%d%d%d",&n,&p,&k);
	rep(i,1,n+1){
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int op=(1<<p)-1;
	rep(i,1,n+1)rep(j,0,p)scanf("%d",&s[i][j]);
	rep(i,1,p+k+1){
		rep(mask,0,1<<p){
			if(st[mask]>i-1)continue;
			upd(dp[i-st[mask]][mask],dp[i-st[mask]-1][mask]+a[i].v);
			int pos=op^mask;
			while(pos){
				upd(dp[i-st[mask]-1][mask|lb(pos)],dp[i-st[mask]-1][mask]+s[a[i].id][Log[lb(pos)]]);
				pos^=lb(pos);
			}
			
		}
	}
	rep(i,p+k+1,n+1){
		per(mask,0,1<<p){
			int pos=mask;
			while(pos){
				upd(dp[k][mask],dp[k][mask^lb(pos)]+s[a[i].id][Log[lb(pos)]]);
				pos^=lb(pos);
			}
		}
	}
	printf("%lld",dp[k][op]);
}