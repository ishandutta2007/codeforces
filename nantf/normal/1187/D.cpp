#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030;
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
int t,n,a[maxn],b[maxn],ta[maxn],tb[maxn],mn[maxn*4],len[maxn];
vector<int> at[maxn];
inline void pushup(int o){
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void build(int o,int l,int r){
	if(l==r) return void(mn[o]=a[l]);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int p,int v){
	if(l==r) return void(mn[o]=v);
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return mn[o];
	int mid=(l+r)>>1,ans=2e9;
	if(mid>=ql) ans=min(ans,query(lson,ql,qr));
	if(mid<qr) ans=min(ans,query(rson,ql,qr));
	return ans;
}
int main(){
	t=read();
	while(t--){
		bool flag=true;
		n=read();
		FOR(i,1,n) ta[i]=a[i]=read(),at[a[i]].push_back(i);
		FOR(i,1,n) tb[i]=b[i]=read();
		sort(ta+1,ta+n+1);sort(tb+1,tb+n+1);
		FOR(i,1,n) if(ta[i]!=tb[i]){puts("NO");flag=false;break;}
		if(!flag){
			FOR(i,1,n) at[i].clear(),len[i]=0;
			continue;
		}
		build(1,1,n);
		FOR(i,1,n){
			int p=at[b[i]][len[b[i]]++];
			if(query(1,1,n,1,p)!=b[i]){puts("NO");flag=false;break;}
			update(1,1,n,p,2e9);
		}
		if(flag) puts("YES");
		FOR(i,1,n) at[i].clear(),len[i]=0;
	}
}