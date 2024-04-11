#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
int n,m,l[maxn],ans[maxn];
ll suf[maxn];
int main(){
	n=read();m=read();
	FOR(i,1,m) l[i]=read();
	ROF(i,m,1) suf[i]=suf[i+1]+l[i];
	if(suf[1]<n) return puts("-1"),0;
	FOR(i,1,m) if(i+l[i]-1>n) return puts("-1"),0;
	FOR(i,1,m) printf("%lld ",max(1ll*i,n-suf[i]+1));
}