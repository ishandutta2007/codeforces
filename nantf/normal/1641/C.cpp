#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,q;
set<int> s,seg[maxn];
void update(int o,int l,int r,int p,int v){
	seg[o].insert(v);
	if(l==r) return void();
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
}
int query(int o,int l,int r,int ql,int qr,int x){
	if(l>=ql && r<=qr){
		auto it=seg[o].lower_bound(x);
		return it==seg[o].end()?1e9:*it;
	}
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr,x);
	if(mid>=qr) return query(lson,ql,qr,x);
	return min(query(lson,ql,qr,x),query(rson,ql,qr,x));
}
int main(){
	n=read();q=read();
	FOR(i,1,n) s.insert(i);
	while(q--){
		int tp=read();
		if(tp){
			int x=read();
			auto it=s.lower_bound(x);
			if(it==s.end() || *it!=x) puts("NO");
			else{
				int l=0,r=1e9;
				if(++it!=s.end()) r=*it;
				if(--it!=s.begin()) l=*--it;
				int ans=query(1,1,n,l+1,x,x);
//				printf("%d %d %d\n",l,r,ans);
				puts(ans<r?"YES":"N/A");
			}
		}
		else{
			int l=read(),r=read();tp=read();
			if(tp){
				update(1,1,n,l,r);
			}
			else{
				auto it=s.lower_bound(l),it1=it;
				while(it1!=s.end() && *it1<=r) it1++;
				s.erase(it,it1);
			}
		}
	}
}