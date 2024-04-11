#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
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
int n,k,a[maxn],cur[maxn];
ll ans;
priority_queue<PII> pq;
inline ll calc(int n,int k){
	return 1ll*(n%k)*(n/k+1)*(n/k+1)+1ll*(k-n%k)*(n/k)*(n/k);
}
inline ll calc2(int n,int k){
	if(n==k) return calc(n,k);
	else return calc(n,k)-calc(n,k+1);
} 
int main(){
	n=read();k=read();
	FOR(i,1,n){
		a[i]=read();
		ans+=1ll*a[i]*a[i];
		cur[i]=1;
		if(a[i]!=cur[i]) pq.push(MP(calc2(a[i],cur[i]),i));
	}
	k-=n;
	while(k){
		k--;
		int id=pq.top().second;pq.pop();
		ans-=calc2(a[id],cur[id]);
		if(++cur[id]!=a[id]) pq.push(MP(calc2(a[id],cur[id]),id));
	}
	printf("%lld\n",ans);
}