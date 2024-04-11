#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
int n,m,l[maxn],p[maxn];
char s[maxn];
inline int query(){
	printf("? %s\n",s+1);
	fflush(stdout);
	return read();
}
inline bool cmp(int x,int y){
	return l[x]>l[y];
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		FOR(j,1,m) s[j]='0'+(i==j);
		l[i]=query();
	}
	FOR(i,1,m) s[i]='1',p[i]=i;
	sort(p+1,p+m+1,cmp);
	int x=query();
	FOR(ii,1,m-1){
		int i=p[ii];
		s[i]='0';
		int y=query();
		if(x-y==l[i]){s[i]='1';continue;}
		x=y;
	}
	int ans=0;
	FOR(i,1,m) if(s[i]=='1') ans+=l[i];
	printf("! %d\n",ans);
	fflush(stdout);
}