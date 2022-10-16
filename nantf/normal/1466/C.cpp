#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int n,f[maxn][2][2];
char s[maxn];
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,0,n) f[i][0][0]=f[i][0][1]=f[i][1][0]=f[i][1][1]=1e9;
	f[0][1][1]=0;
	FOR(i,1,n){
		FOR(a,0,1) FOR(b,0,1) FOR(c,0,1){
			if(a || ((b || s[i]!=s[i-1]) && (c || s[i]!=s[i-2])))
				f[i][a][b]=min(f[i][a][b],f[i-1][b][c]+a);
		} 
	}
	printf("%d\n",min(min(f[n][0][0],f[n][0][1]),min(f[n][1][0],f[n][1][1])));
}
int main(){
	int T=read();
	while(T--) solve();
}