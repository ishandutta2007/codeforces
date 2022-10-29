#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
const ll Inf=1e18;
int a[N],vis[N];
int stk[N],ans[N];
int mex(int n){
	rep(i,0,n)vis[i]=0;
	rep(i,0,n)vis[a[i]]=1;
	int ans=n;
	rep(i,0,n){
		if(!vis[i]){
			ans=i;
			break;
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		rep(i,0,n)scanf("%d",&a[i]);
		int cnt=0;
		rep(i,0,2*n){
			int val=mex(n);
			if(val==n){
				int ok=0;
				per(i,0,n){
					if(a[i]!=i){
						ans[cnt++]=i;
						a[i]=val;
						ok=1;
						break;
					}
				}
				if(!ok)break;
			}
			else{
				ans[cnt++]=val;
				a[val]=val;
			}
		}
		printf("%d\n",cnt);
		rep(i,0,cnt)printf("%d ",ans[i]+1);
		printf("\n");
	//	rep(i,0,n)printf("%d ",a[i]);printf("A\n\n");
	}
}