#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int> 
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1005;
const ll mod=998244353;
vi g[N<<1];
char s[N],a[N<<1];
int sum[N],vis[N];
int n;
ll fac;
void dfs(int u,int fa){
	int j=u>n?u-n:u;
	--sum[j];
	for(auto v:g[u]){
		if(v==fa)continue;
		if(abs(u-v)==n){
			a[v]=((s[j]-'0')^(a[u]-'0'))+'0';
		}
		else{
			a[v]=a[u];
		}
		dfs(v,u);
	}
}
bool check(){
	rep(i,1,n+1){
		if(!sum[i]&&s[i]!='?'){
			if((a[i]-48)^(a[i+n]-48)!=s[i]-48)return 1;
		}
	}
	return 0;
}
int main(){
	ll ans=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	reverse(s+1,s+1+n);
	if(s[1]=='1')return cout<<0,0;
	if(s[1]=='?')s[1]='0';
	rep(len,1,n){
		rep(j,1,2*n+1)a[j]='?',g[j].clear();
		rep(j,len+n+1,2*n+1)a[j]='0';
		a[1]=a[n]=a[n+1]=a[n+len]='1';
		int l=2,r=n-1;
		while(l<r){g[l].pb(r),g[r--].pb(l++);}
		l=2,r=len-1;
		while(l<r){
			g[l+n].pb(r+n),g[r+n].pb(l+n);
			++l,--r;
		}
		rep(j,1,n+1){
			sum[j]=0;
			if(a[j]=='?')++sum[j];
			if(a[j+n]=='?')++sum[j];
			if(sum[j]==2&&s[j]!='?')g[j].pb(j+n),g[j+n].pb(j);
		//	cout<<sum[j]<<' ';
		}
//	cout<<a+1<<endl;
		rep(j,1,n+1){
			if(sum[j]==1&&s[j]!='?'){
				if(a[j]=='?'){
					a[j]=((s[j]-'0')^(a[j+n]-'0'))+48;
			//	cout<<j<<' '<<s[j]<<' '<<a[j+n]<<' '<<a[j]<<"check\n";
					dfs(j,-1);
				}
				else{
					a[j+n]=((s[j]-'0')^(a[j]-'0'))+48;
					dfs(j+n,-1);
				}
			}
		}
//	cout<<a+1<<endl;
//	system("pause");
		if(check())continue;
		fac=1;
		rep(j,1,n+1){
			if(sum[j]==1){
				fac=fac*2%mod;
				if(a[j]=='?'){
					a[j]=48;
					dfs(j,-1);
				}
				else{
					a[j+n]=48;
					dfs(j+n,-1);
				}
			}
			if(sum[j]==2){
				fac=fac*2%mod;
				a[j]=48;
				dfs(j,-1);
				--j;
			}
		}
		ans=(ans+fac)%mod;
	}
	printf("%lld",ans);
}