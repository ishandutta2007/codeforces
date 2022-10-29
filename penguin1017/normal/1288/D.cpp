#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define lb(x) ((x)&(-x))
using namespace std;
const int N=3e5+9;
const ll mod=1e9+7;
int vis[1<<8],a[N][8],op,n,m;
pii ans;
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
bool check(int val){
	memset(vis,0,sizeof vis);
	rep(i,1,n+1){
		int pos=0;
		rep(j,0,m){
			if(a[i][j]>=val)pos^=1<<j;
		}
		vis[pos]=i;
	}
	rep(i,0,op+1){
		rep(j,0,op+1){
			if(((i|j)==op)&&vis[i]&&vis[j]){
				ans={vis[i],vis[j]};
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int maxn=0,mini=1e9+2;
	scanf("%d%d",&n,&m);
	op=(1<<m)-1;
	rep(i,1,n+1){
		rep(j,0,m){
			scanf("%d",&a[i][j]);
			maxn=max(maxn,a[i][j]);
			mini=min(mini,a[i][j]);
		}
	}
	int l=mini,r=maxn+1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%d %d",ans.fi,ans.se);
}