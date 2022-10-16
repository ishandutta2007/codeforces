#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,nxt[maxn][26],lst[2][26];
char s[maxn],t[maxn];
void solve(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	FOR(i,1,n/2) swap(s[i],s[n+1-i]);
	FOR(i,1,m/2) swap(t[i],t[m+1-i]);
	FOR(i,0,25) nxt[n+1][i]=lst[0][i]=lst[1][i]=n+1;
	ROF(i,n,0){
		FOR(j,0,25) nxt[i][j]=lst[(i&1)^1][j];
		if(i) lst[i&1][s[i]-'a']=i;
	}
	int now=0;
	FOR(i,1,m) now=nxt[now][t[i]-'a'];
	puts(now<=n?"YES":"NO");
}
int main(){
	int T;
	read(T);
	while(T--) solve(); 
}