#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=600060;
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
struct ques{
	int l,r,id;
	bool operator<(const ques &q)const{return r<q.r;}
}q[maxn];
int n,m,a[maxn],lst[maxn],at[maxn],lft[maxn],rig[maxn],Q,bit[maxn],suf[maxn],cnt[maxn];
bool vis[maxn];
inline void update(int p,int v){
	for(int i=p;i<=m;i+=i&-i) bit[i]+=v;
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=bit[i];
	return s;
}
inline int query(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	n=read();m=read();
	FOR(i,1,m) lft[a[i]=read()]=1;
	FOR(i,1,n){
		rig[i]=i;
		if(!lft[i]) lft[i]=i;
	}
	ROF(i,n+m,n+1) a[i]=a[i-n];
	FOR(i,1,n) a[i]=n-i+1;
	m+=n;
	FOR(i,1,m){
		lst[i]=at[a[i]];
		at[a[i]]=i;
		if(lst[i] && lst[i]+1<=i-1) q[++Q]=(ques){lst[i]+1,i-1,a[i]};
	}
	sort(q+1,q+Q+1);
	int cur=1;
	FOR(i,1,Q){
		while(cur<=q[i].r){
			update(cur,1);
			if(lst[cur]) update(lst[cur],-1);
			cur++;
		}
		rig[q[i].id]=max(rig[q[i].id],query(q[i].l,q[i].r)+1);
	}
	ROF(i,m,1){
		if(!vis[a[i]]){
			suf[i]=suf[i+1]+1;
			vis[a[i]]=true;
			rig[a[i]]=max(rig[a[i]],suf[i+1]+1);
		}
		else suf[i]=suf[i+1];
	}
	FOR(i,1,n) printf("%d %d\n",lft[i],rig[i]);
}
// /fad