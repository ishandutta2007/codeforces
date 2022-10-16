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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,tx[maxn],txl,ty[maxn],tyl,xl[maxn],xr[maxn],yl[maxn],yr[maxn];
struct seg{
	int x,yl,yr,tp,id;
	bool operator<(const seg &s)const{return x<s.x;}
}s[maxn];
set<int> st[maxn];
int mx[maxn],mn[maxn];
bool in[maxn];
inline void pushup(int o){
//	printf("pushup %d in\n",o);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
	if(!st[o].empty()){
		int tmp=*st[o].rbegin();
		if(!in[tmp]) mx[o]=max(mx[o],tmp);
		else mn[o]=max(mn[o],tmp);
		if(mx[o]<mn[o]) mx[o]=-1e9;
	}
//	printf("pushup %d out\n",o);
}
void build(int o,int l,int r){
	mn[o]=mx[o]=-1e9;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lson);build(rson);
}
void update(int o,int l,int r,int ql,int qr,int v,int tp){
//	printf("update(%d,%d,%d,%d,%d,%d,%d)\n",o,l,r,ql,qr,v,tp);
	if(l>=ql && r<=qr){
		if(tp==1) st[o].insert(v);
		else st[o].erase(v);
//		puts("in");
		if(l==r){
			mn[o]=mx[o]=-1e9;
			if(!st[o].empty()){
				int tmp=*st[o].rbegin();
				if(!in[tmp]) mx[o]=max(mx[o],tmp);
				else mn[o]=max(mn[o],tmp);
				if(mx[o]<mn[o]) mx[o]=-1e9;
			}
		}
		else pushup(o);
//		puts("out");
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v,tp);
	if(mid<qr) update(rson,ql,qr,v,tp);
	pushup(o);
}
int main(){
	n=read();
	FOR(i,1,n){
		xl[i]=read(),yl[i]=read(),xr[i]=read(),yr[i]=read();
		tx[++txl]=xl[i];tx[++txl]=xr[i];
		ty[++tyl]=yl[i];ty[++tyl]=yr[i];
	}
	sort(tx+1,tx+txl+1);txl=unique(tx+1,tx+txl+1)-tx-1;
	sort(ty+1,ty+tyl+1);tyl=unique(ty+1,ty+tyl+1)-ty-1;
	FOR(i,1,2*n){
		xl[i]=lower_bound(tx+1,tx+txl+1,xl[i])-tx;
		xr[i]=lower_bound(tx+1,tx+txl+1,xr[i])-tx-1;
		yl[i]=lower_bound(ty+1,ty+tyl+1,yl[i])-ty;
		yr[i]=lower_bound(ty+1,ty+tyl+1,yr[i])-ty-1;
		s[2*i-1]=(seg){xl[i],yl[i],yr[i],1,i};
		s[2*i]=(seg){xr[i]+1,yl[i],yr[i],-1,i};
	}
	sort(s+1,s+2*n+1);
	build(1,1,tyl);
	int cur=1;
	FOR(i,1,txl){
		while(cur<=2*n && s[cur].x<=i){
//			printf("cur=%d\n",cur);
			update(1,1,tyl,s[cur].yl,s[cur].yr,s[cur].id,s[cur].tp);
//			puts("done");
			cur++;
		}
		while(mx[1]!=-1e9){
			in[mx[1]]=true;
//			printf("mx[1]=%d\n",mx[1]);
//			puts("in updateeeeeeeeeee");
			update(1,1,tyl,yl[mx[1]],yr[mx[1]],mx[1],1);
//			puts("out updateeeeeeeeeee");
		}
	}
	int ans=1;
	FOR(i,1,n) if(in[i]) ans++;
	printf("%d\n",ans);
}