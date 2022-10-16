#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m;
char s[maxn][maxn];
void solve(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",s[i]+1);
	int tp=-1;
	FOR(i,1,n) FOR(j,1,m) if(s[i][j]!='.'){
		int tmp=-1;
		if(s[i][j]=='W') tmp=(i+j)&1;
		if(s[i][j]=='R') tmp=((i+j)&1)^1;
		if(tp==-1) tp=tmp;
		else if(tp!=tmp) return puts("NO"),void();
	}
	if(tp==-1) tp=0;
	puts("YES");
	FOR(i,1,n){
		FOR(j,1,m) if(tp^((i+j)&1)) putchar('R');
		else putchar('W');
		puts("");
	}
}
int main(){
	int T=read();
	while(T--) solve();
}