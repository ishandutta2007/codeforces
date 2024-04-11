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
ll inv[N],jie[N];
void pre(){
	jie[0]=1,inv[0]=inv[1]=1;
	rep(i,2,N)inv[i]=-inv[mod%i]*(mod/i)%mod+mod;
	rep(i,1,N)jie[i]=jie[i-1]*i%mod,inv[i]=inv[i]*inv[i-1]%mod;
}
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	pre();
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==2){
		cout<<0;
		return 0;
	}
	ll ans=jie[m]*inv[n-1]%mod*inv[m-(n-1)]%mod*(n-2)%mod*quick(2,n-3)%mod;
	cout<<ans;
}