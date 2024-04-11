#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,f[maxn][8][8],a[maxn];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n) a[i]=s[i]-'0';
	f[0][7][7]=1;
	FOR(i,0,n-1) FOR(j,0,7) FOR(k,0,7) if(f[i][j][k]){
		int x=(j&1)?a[i+1]:1,y=(j&2)?a[i+1]:1,z=(j&4)?a[i+1]:1;
		FOR(p,0,x) FOR(q,0,y) FOR(r,0,z){
			int jj=j,kk=k;
			if(p!=x) jj&=~1;
			if(q!=y) jj&=~2;
			if(r!=z) jj&=~4;
			int pp=p^q,qq=q^r,rr=p^r;
			if(pp&qq) kk&=~1;
			if(qq&rr) kk&=~2;
			if(pp&rr) kk&=~4;
			f[i+1][jj][kk]=(f[i+1][jj][kk]+f[i][j][k])%mod;
		}
	}
	int ans=0;
	FOR(i,0,7) ans=(ans+f[n][i][0])%mod;
	printf("%d\n",ans);
}