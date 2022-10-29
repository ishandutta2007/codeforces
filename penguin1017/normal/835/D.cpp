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
using namespace std;
const int N=5002;
const int pp=131;
const ll mod=998244353;
int a[N][N],ans[N];
bool vis[N][N];
ll pre[N],suf[N],mul[N];
char s[N];
ll gp(int p,int len){
	ll res=(pre[p-1]*mul[len]-pre[p+len-1])%mod;
	return (res+mod)%mod;
}
ll gs(int p,int len){
	ll res=(suf[p+len]*mul[len]-suf[p])%mod;
	return (res+mod)%mod;
}
void check(int p,int len){
	if(gp(p,len)!=gs(p,len))return;
	int pos=p+len/2;
	a[p][len]=a[p][len>>1]+1;
}
int main(){
	pre[0]=1;
	mul[0]=1;
	rep(i,1,N)mul[i]=mul[i-1]*pp%mod;
	scanf("%s",s+1);
	int n=strlen(s+1);
	suf[n+1]=1;
	rep(i,1,n+1)pre[i]=(pre[i-1]*pp+s[i])%mod;
	per(i,1,n+1)suf[i]=(suf[i+1]*pp+s[i])%mod;
	rep(len,1,n+1){
		rep(i,1,n+1){
			if(i+len-1>n)break;
			check(i,len);
		//	cout<<a[i][len]<<"check\n";
			ans[a[i][len]]++;
		}
	}
	per(i,1,n+1)ans[i]+=ans[i+1];
	rep(i,1,n+1)printf("%d ",ans[i]);
}