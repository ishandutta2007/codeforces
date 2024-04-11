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
ll ans[N],ten[N];
int main(){
	ten[0]=1;
	rep(i,1,N)ten[i]=ten[i-1]*10%mod;
	int n;
	scanf("%d",&n);
	rep(len,1,n-1){
		int last=n-len;
		ans[len]=(last-1)*81*ten[last-2]%mod+2*9*ten[last-1]%mod;
		ans[len]=ans[len]*10%mod;
	}
	ans[n]=10;
	ans[n-1]=180;
	rep(i,1,n+1)printf("%lld ",ans[i]);
/*	ll tot=0;
	rep(i,1,n+1)tot+=i*ans[i];
	cout<<tot;*/
}