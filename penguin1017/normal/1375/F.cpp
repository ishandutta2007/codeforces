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
ll a[4];
int main(){
	rep(i,1,4)scanf("%d",&a[i]);
	printf("First\n");
	//fflush(stdout);
	//////
	ll maxn=0;
	rep(i,1,4)maxn=max(maxn,a[i]);
	printf("%lld\n",maxn); 
	fflush(stdout);
	/////
	int id;
	scanf("%d",&id);
	a[id]+=maxn;
	ll sum=0;
	rep(i,1,4)sum+=a[id]-a[i];
	printf("%lld\n",sum);
	fflush(stdout);
	////// 
	scanf("%d",&id);
	a[id]+=sum;
	ll mini=1e12;
	rep(i,1,4){
		if(id==i)continue;
		mini=min(a[id]-a[i],mini); 
	}
	printf("%lld\n",mini);
	fflush(stdout);
	scanf("%d",&id);
	if(id==0)return 0;
}