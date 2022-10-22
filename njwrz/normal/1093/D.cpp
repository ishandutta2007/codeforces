#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
inline void write(ll X)
{
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) write(X/10);
	putchar(X%10+'0');
}
ll mod=998244353,shuchu;
vector <ll> v[300005];
ll n,f[300005],ans[5];
ll po(ll a,ll b){
	if(b==0)return 1;
	else return po(a,b/2)*po(a,b/2)*(ll)pow(a,(b&1))%mod;
}
void dfs(ll p,ll c){
	if(f[p]){
		if(f[p]!=c)shuchu=0;
		return;
	}
	f[p]=c;
	ans[c]++;
	for(ll i=0;i<v[p].size();i++)dfs(v[p][i],3-c);
}
int main(){
	ll k,n,m;
	k=read();
	ll x,y;
	for(ll i=0;i<k;i++){
		n=read();m=read();
		for(ll j=1;j<=n;j++)v[j].clear(),f[j]=0;
		shuchu=1;
		for(ll j=0;j<m;j++){
			x=read();y=read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(ll j=1;j<=n;j++){
			if(!f[j]){
				ans[1]=0;ans[2]=0;
				dfs(j,1);
				shuchu=shuchu*(po(2,ans[1])+po(2,ans[2]))%mod;
			}
		}
		write(shuchu);putchar('\n');
	}
	return 0;
}