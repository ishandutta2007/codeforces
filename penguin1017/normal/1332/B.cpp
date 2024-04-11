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
const int N=2e6+9;
const ll mod=998244353;
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
int a[N],vis[11],ans[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		rep(i,0,n){
			scanf("%d",&a[i]);
			rep(k,0,11){
				if(a[i]%p[k]==0){
					ans[i]=k;
					vis[k]=1;
					break;
				}
			}
		}
		int cnt=0;
		rep(i,0,11)if(vis[i])vis[i]=++cnt;
		printf("%d\n",cnt);
		rep(i,0,n)printf("%d ",vis[ans[i]]);
		printf("\n");
	}
}