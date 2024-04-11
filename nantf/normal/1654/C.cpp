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
int n;
ll a[maxn];
priority_queue<ll> pq;
void clear(){
	while(!pq.empty()) pq.pop();
}
void solve(){
	n=read();
	ll s=0;
	FOR(i,1,n) s+=a[i]=read();
	pq.push(s);
	sort(a+1,a+n+1);
	int cur=n;
	bool flag=true;
	while(cur>=1){
		ll x=pq.top();pq.pop();
		if(x<a[cur]){flag=false;break;}
		if(x==a[cur]) cur--;
		else pq.push(x/2),pq.push((x+1)/2);
	}
	puts(flag?"YES":"NO");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}