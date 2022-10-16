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
ll p;
int q,tmp[maxn],cnt[maxn],tl;
void solve(){
	p=read();q=read();
	if(p%q!=0) printf("%lld\n",p);
	else{
		ll tmpq=q;
		tl=0;
		FOR(i,2,sqrt(q)) if(q%i==0){
			tmp[++tl]=i;
			while(q%i==0) q/=i,cnt[tl]++;
		}
		if(q>1) tmp[++tl]=q,cnt[tl]=1;
		ll ans=0;
		FOR(i,1,tl){
			ll hhh=p;
			while(hhh%tmpq==0) hhh/=tmp[i];
			ans=max(ans,hhh);
		}
		printf("%lld\n",ans);
	}
}
int main(){
	int T=read();
	while(T--) solve();
}