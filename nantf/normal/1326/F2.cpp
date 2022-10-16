#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=22,maxs=266666,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,q,lim,sz[maxs];
ll f[maxs][maxn],A[maxn][maxs],ans[maxs],tmp[maxs]; 
bool mp[maxn][maxn];
map<vector<int>,ll> cnt; 
vector<int> vec;
char s[maxn];
void fmt_suf(ll *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[i+j+k]+=A[j+k];
}
void ifmt_pre(ll *A){
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) A[j+k]-=A[i+j+k];
}
void dfs(int sum,int last){
	if(sum==n){
		FOR(i,0,lim-1) tmp[i]=1;
		FOR(i,0,(int)vec.size()-1){
			int x=vec[i];
			FOR(j,0,lim-1) tmp[j]*=A[x][j];
		}
		ll s=0;
		FOR(i,0,lim-1){
			if((n-sz[i])&1) s-=tmp[i];
			else s+=tmp[i];
		}
		cnt[vec]=s;
		return;
	}
	FOR(i,last,n) if(sum+i<=n){
		vec.PB(i);
		dfs(sum+i,i);
		vec.pop_back();
	}
}
int main(){
	n=read();lim=1<<n;
	FOR(i,0,n-1){
		scanf("%s",s);
		FOR(j,0,n-1) mp[i][j]=s[j]-'0';
	}
	FOR(i,0,n-1) f[1<<i][i]=1;
	FOR(i,1,lim-1) FOR(j,0,n-1) if((i>>j)&1){
		FOR(k,0,n-1) if(!((i>>k)&1) && mp[j][k]) f[i|(1<<k)][k]+=f[i][j];
	}
	FOR(i,1,lim-1) sz[i]=sz[i>>1]+(i&1);
	FOR(i,1,lim-1) FOR(j,0,n-1) A[sz[i]][i]+=f[i][j];
	FOR(i,1,n) fmt_suf(A[i]);
	dfs(0,1);
	FOR(i,0,(lim>>1)-1){
		vector<int> v;
		int c=0;
		FOR(j,0,n-2) if((i>>j)&1) c++;
		else v.PB(c+1),c=0;
		v.PB(c+1);
		sort(v.begin(),v.end());
		ans[i]=cnt[v];
	}
	ifmt_pre(ans);
	FOR(i,0,(lim>>1)-1) printf("%lld ",ans[i]); 
}