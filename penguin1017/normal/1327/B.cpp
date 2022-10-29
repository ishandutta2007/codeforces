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
int L[N],R[N];
vi g[N]; 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,1,n+1){
			int m,v;
			g[i].clear();
			scanf("%d",&m);
			while(m--)scanf("%d",&v),g[i].pb(v);
			sort(all(g[i]));
			L[i]=0;
			R[i]=0;
		}
		int ans=0;
		rep(i,1,n+1){
			for(auto v:g[i]){
				if(!R[v]){
					L[i]=1;
					R[v]=1;
					++ans;
					break;
				}
			}
		}
		if(ans<n){
			printf("IMPROVE\n");
			rep(i,1,n+1){
				if(!L[i]){
					printf("%d ",i);
					break;
				}
			}
			rep(i,1,n+1){
				if(!R[i]){
					printf("%d\n",i);
					break;
				}
			}
		}
		else{
			printf("OPTIMAL\n");
		}
	}
}