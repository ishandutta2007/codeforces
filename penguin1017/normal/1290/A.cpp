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
const int N=4e4+9;
const ll mod=998244353;
int a[N];
int l[N][20],r[N][20],suf[N],pre[N];
int main(){
	int n,m,k,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n+1)scanf("%d",&a[i]);
		rep(i,0,n)pre[i]=a[i+1],suf[i]=a[n-i];
		k=min(k,m-1);
		rep(i,0,m)l[i][0]=r[i][0]=max(pre[i],suf[m-1-i]);
		for(int i=1;(1<<i)<=m;++i){
			rep(j,0,m){
				if(j+(1<<i)>m)break;
				l[j][i]=min(l[j][i-1],l[j+(1<<i-1)][i-1]);
			}
			per(j,0,m){
				if(j<(1<<i)-1)break;
				r[j][i]=min(r[j][i-1],r[j-(1<<i-1)][i-1]);
			}
		}
		k=m-k;
		int pos=0;
		while(1<<pos<=k)++pos;
		int ans=0;
		--pos;
		rep(i,0,m){
			if(i+k>m)break;
			ans=max(ans,min(l[i][pos],r[i+k-1][pos]));
		}
		printf("%d\n",ans);
	}
}