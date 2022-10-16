#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
struct hhh{
	ll s;
	int id;
	bool operator<(const hhh &h)const{
		if(s!=h.s) return s<h.s;
		return id<h.id;
	}
}h[maxn];
int n,p[maxn];
ll s[maxn],bit[maxn];
inline void update(int p,int v){
	for(int i=p;i<=n;i+=i&-i) bit[i]+=v;
}
inline ll query(int p){
	ll s=0;
	for(int i=p;i;i-=i&-i) s+=bit[i];
	return s;
}
int main(){
	n=read();
	FOR(i,1,n) s[i]=read();
	FOR(i,1,n) update(i,i);
	ROF(i,n,1){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(query(mid-1)>s[i]) r=mid-1;
			else l=mid;
		}
		p[i]=l;
		update(l,-l);
	}
	FOR(i,1,n) printf("%d ",p[i]);
}