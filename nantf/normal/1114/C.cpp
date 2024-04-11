#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
ll n,b,fac[maxn],ans=LLONG_MAX;
int cnt[maxn],len;
void split(ll x){
	for(ll i=2;i*i<=x;i++)
		if(x%i==0){
			fac[++len]=i;
			while(x%i==0) cnt[len]++,x/=i;
		}
	if(x>1) fac[++len]=x,cnt[len]=1;
}
int main(){
	n=read();b=read();
	split(b);
	FOR(i,1,len){
		ll s=0;
		for(ll pr=fac[i],ppr=1;pr<=n && pr>0;ppr=pr,pr*=fac[i]){
			if(pr/fac[i]!=ppr) break;
			s+=n/pr;
		}
		ans=min(ans,s/cnt[i]);
	}
	printf("%I64d\n",ans);
}