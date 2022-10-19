#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)	for(ll i=(ll)(x);i>=(ll)(y);--i)
#define rep(i,x,y)	for(ll i=(ll)(x);i<(ll)(y);++i)
char s[1000],t[1000],tt[1000],ttt[1000];
ll f[510][510],g[510][510],ans[510][2],n,m;
inline void Min(ll &x,ll y){
	x=x<y?x:y;
}
inline bool same(ll l,ll r,ll pos){
	FOr(i,r,l){
		if(t[i]!=tt[pos])return 0;
		--pos;
	}
	return 1;
}
int main(){
	cin>>n>>m;
	scanf("%s",s+1);
	scanf("%s",t+1);
	For(i,1,m){
		tt[i]='0';
		for(ans[i-1][0]=i;ans[i-1][0]&&!same(1,ans[i-1][0],i);)--ans[i-1][0];
		tt[i]='1';
		for(ans[i-1][1]=i;ans[i-1][1]&&!same(1,ans[i-1][1],i);)--ans[i-1][1];
		tt[i]=t[i];
	}
	ll fafa=m-1;
	for(;!same(1,fafa,m);)--fafa;
	memset(f,60,sizeof f);
	f[0][0]=0;
	For(i,1,n){
		memset(g,60,sizeof g);
		For(tot_pipei,0,i)
		For(cur_pipei,0,m-1)
		if (f[tot_pipei][cur_pipei]<=n)
		For(v,'0','1'){
			ll tot_pipei1=tot_pipei,cur_pipei1;
			cur_pipei1=ans[cur_pipei][v-'0'];
			if (cur_pipei1==m){
				++tot_pipei1;
				cur_pipei1=fafa;
			}
//			cout<<i<<' '<<tot_pipei<<' '<<cur_pipei<<' '<<tot_pipei1<<' '<<cur_pipei1<<endl;
			Min(g[tot_pipei1][cur_pipei1],f[tot_pipei][cur_pipei]+(s[i]!=v));
		}
		memcpy(f,g,sizeof g);
	}
	For(tot_pipei,0,n-m+1){
		ll ans=1e9;
		For(now,0,m-1)ans=min(ans,f[tot_pipei][now]);
		if (ans>n)	cout<<"-1 ";
		else		cout<<ans<<' ';
	}
}