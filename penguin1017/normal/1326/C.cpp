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
int a[N];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%d",&a[i]);
	ll ans=0;
	rep(i,n-k+1,n+1)ans+=i;
	printf("%lld ",ans);
	int cnt=0,last;
	ans=1;
	rep(i,0,n){
		if(a[i]>n-k){
			++cnt;
			if(cnt>1){
				ans=ans*(i-last)%mod;
			}
			last=i;
		}
	}
	printf("%lld",ans);
}