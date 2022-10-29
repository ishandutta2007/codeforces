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
const int N=2e3+9;
const ll mod=998244353;
const ll Inf=1e18;
bool vis[N],ok[N];
int pos[N];
int main(){
	int n;
	scanf("%d",&n);
	int sqr=sqrt(n+0.5);
	rep(i,1,n+1){
		if(i%sqr)ok[i]=1;
	}
	int t=1000;
	while(t--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!ok[i])continue;
			if(!vis[i])pos[cnt++]=i,vis[i]=1;
			if(cnt==sqr)break;
		}
		printf("%d ",cnt);
		rep(i,0,cnt)printf("%d ",pos[i]);
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d",&x);
		rep(i,0,cnt){
			vis[(x+i-1)%n+1]=0;
		}
	}
	cout<<0<<endl;
	fflush(stdout);
	return 0;
}