#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=18;
int n;
char s[maxn+5][maxn+5];
int cnt[(1<<maxn)+5];
typedef long long ll;
ll dp[(1<<maxn)+5][maxn+5],f[maxn+5][(1<<maxn)+5];
void FWT_or(ll* f,int n,bool flag){
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++) f[k+i]+=f[k]*(flag?1:-1);
}
void FWT_and(ll* f,int n,bool flag){
	for(int i=1;i<n;i*=2) for(int j=0;j<n;j+=i*2)
		for(int k=j;k<j+i;k++) f[k]+=f[k+i]*(flag?1:-1);
}
ll g[maxn+5][(1<<maxn)+5],h[(1<<(maxn-1))+5];
vector<int> p;
map<vector<int>,ll> mp;
void dfs(int c,int u,int k){
	if(!u){
		ll res=0;
		for(int i=0;i<(1<<n);i++) res+=g[c][i]*((n-cnt[i])%2==0?1:-1);
		mp[p]=res;
		return;
	}
	for(int i=k;i<=u;i++){
		p.push_back(i);
		for(int j=0;j<(1<<n);j++) g[c+1][j]=g[c][j]*f[i][j];
		dfs(c+1,u-i,i);
		p.pop_back();
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=1;i<(1<<n);i++) cnt[i]=cnt[i>>1]+(i&1);
	for(int i=0;i<n;i++) dp[1<<i][i]=1;
	for(int i=1;i<(1<<n);i++) if(cnt[i]>1)
		for(int j=0;j<n;j++) if(i>>j&1) for(int k=0;k<n;k++)
			if((i>>k&1)&&s[j][k]=='1') dp[i][j]+=dp[i^(1<<j)][k];
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<n;j++) if(i>>j&1) f[cnt[i]][i]+=dp[i][j];
	for(int i=1;i<=n;i++) FWT_or(f[i],1<<n,1);
	for(int i=0;i<(1<<n);i++) g[0][i]=1;
	dfs(0,n,1);
	for(int i=0;i<(1<<(n-1));i++){
		vector<int> ord;
		int lst=-1;
		for(int j=0;j<n-1;j++) if(!(i>>j&1)){
			ord.push_back(j-lst);
			lst=j;
		}
		ord.push_back(n-1-lst);
		sort(ord.begin(),ord.end());
		h[i]=mp[ord];
	}
	FWT_and(h,1<<(n-1),0);
	for(int i=0;i<(1<<(n-1));i++) printf("%lld ",h[i]);
	return 0;
}