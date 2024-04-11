#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
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
int n,k,a[maxn];
ll suf[maxn],ans;
int main(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	ROF(i,n,1) suf[i]=suf[i+1]+a[i];
	if(!k){
		FOR(i,2,n) ans+=suf[i];
		printf("%lld\n",ans);
		return 0;
	}
	FOR(i,2,n) if(suf[i]>=0 || i%(k+1)==1) ans+=suf[i];
	printf("%lld\n",ans);
}