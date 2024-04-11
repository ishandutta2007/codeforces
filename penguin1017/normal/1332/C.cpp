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
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=2e5+9;
const ll mod=998244353;
int vis[N][26],sum[N];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
char s[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		rep(i,1,n+1)fa[i]=i,sum[i]=0;
		rep(i,1,n+1)rep(j,0,26)vis[i][j]=0;
		int ans=0;
		scanf("%s",s+1);
		rep(i,1,n+1)fa[find(i)]=find(n+1-i);
		rep(i,1,n-k+1)fa[find(i)]=find(i+k);
		rep(i,1,n+1){
			int p=find(i);
			sum[p]++;
			vis[p][s[i]-'a']++;
		}
		rep(i,1,n+1){
			int maxn=0;
			int p=find(i);
			if(sum[p]){
				rep(j,0,26)maxn=max(maxn,vis[p][j]);
			}
			ans+=sum[p]-maxn;
			sum[p]=0;
		}
		printf("%d\n",ans);
	}
}