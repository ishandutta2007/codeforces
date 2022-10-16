#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
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
int n,deg[maxn],ans[maxn],al;
char s[maxn];
void clear(){
	al=0;
	FOR(i,1,2*n+1) deg[i]=0;
}
void dfs(int now){
	while(deg[now]){
		deg[now]--;
		dfs(now+1);
		ans[++al]=0;
	}
	while(deg[now-1]){
		deg[now-1]--;
		dfs(now-1);
		ans[++al]=1;
	}
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int now=n+1;
	FOR(i,1,n){
		if(s[i]=='0') deg[now++]++;
		else deg[--now]++;
	}
	dfs(n+1);
	ROF(i,al,1) printf("%d",ans[i]);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}