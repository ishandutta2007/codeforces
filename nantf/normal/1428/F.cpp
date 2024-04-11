#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222222,mod=998244353;
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
int n,mn[maxn],add[maxn];
char s[maxn];
ll ans,sum[maxn];
inline void pushup(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
inline void setadd(int o,int l,int r,int v){
	add[o]+=v;
	mn[o]+=v;
	sum[o]+=1ll*(r-l+1)*v;
}
inline void pushdown(int o,int l,int r){
	int mid=(l+r)>>1;
	if(add[o]){
		setadd(lson,add[o]);
		setadd(rson,add[o]);
		add[o]=0;
	}
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setadd(o,l,r,v);
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
int query(int o,int l,int r,int v){
	if(l==r) return l;
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	if(mn[o<<1]>=v) return query(rson,v);
	else return query(lson,v);
}
int main(){
	n=read();
	scanf("%s",s+1);
	int cnt=0;
	FOR(i,1,n){
		if(s[i]=='1'){
			cnt++;
			update(1,1,n,query(1,1,n,cnt),i,1);
		}
		else cnt=0;
		ans+=sum[1];
	}
	printf("%lld\n",ans);
}