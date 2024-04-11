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
const int N=1e6+9;
const ll mod=998244353;
int p=1e9+7;
ll hs[N],hs2[N],mul[N];
char s[N],ans[N],s2[N];
ll get(int l,int r){
	ll ans=hs[r]-mul[r-l]*hs[l];
	ans%=mod;
	ans=(ans+mod)%mod;
	return ans;
}
ll get2(int l,int r){
	ll ans=hs2[r]-mul[r-l]*hs2[l];
	ans%=mod;
	ans=(ans+mod)%mod;
	return ans;
}
void solve(){
	int n=strlen(s2+1);
	rep(i,1,n+1){
		hs[i]=(hs[i-1]*p+s2[i])%mod;
		hs2[i]=(hs2[i-1]*p+s2[n+1-i])%mod;
	}
	int lmax=0,rmax=0;
	rep(i,1,n+1){
		if(hs[i]==get2(n-i,n))lmax=i;
	}
	rep(i,1,n+1){
		if(hs2[i]==get(n-i,n))rmax=i;
	}
	if(lmax>rmax){
		s2[lmax+1]=0;
		printf("%s",s2+1);
	}
	else{
		reverse(s2+1,s2+1+n);
		s2[rmax+1]=0;
		printf("%s",s2+1);
	}
}
int main(){
	mul[0]=1;
	rep(i,1,N)mul[i]=mul[i-1]*p%mod; 
	int t;
	scanf("%d",&t);
	rep(mask,1,t+1){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l=1,r=n,cnt=0;
		while(l<r){
			if(s[l]==s[r])ans[cnt++]=s[l],++l,--r;
			else break;
		}
		ans[cnt]=0;
		printf("%s",ans);
		reverse(ans,ans+cnt);
		cnt=1;
		rep(i,l,r+1)s2[cnt++]=s[i];
		s2[cnt]=0;
		solve();
		printf("%s\n",ans);
	}
}