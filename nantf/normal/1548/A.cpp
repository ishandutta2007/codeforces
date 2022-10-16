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
int n,m,q,d[maxn],ans;
void ins(int x){
	d[x]++;
	if(d[x]==1) ans--;
}
void del(int x){
	d[x]--;
	if(!d[x]) ans++;
}
int main(){
	ans=n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		ins(min(u,v));
	}
	q=read();
	while(q--){
		int op=read();
		if(op==1){
			int u=read(),v=read();
			ins(min(u,v));
		}
		if(op==2){
			int u=read(),v=read();
			del(min(u,v));
		}
		if(op==3) printf("%d\n",ans);
	}
}