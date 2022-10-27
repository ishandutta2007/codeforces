#include<iostream>
#include<cstdio>
#include<vector>
#define inf 2147483647
using namespace std;
typedef long long ll;
const int maxn=200005;
char ch;
inline void rd(int &x){
	x=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
}
inline int mx(int a,int b){
	return a>b?a:b;
}
inline int mn(int a,int b){
	return a<b?a:b;
}

int n,up,x;
ll ans;

int p1[maxn],p2[maxn],p3[maxn],p4[maxn];
vector<int>q1[maxn],q2[maxn];// 

namespace Segment_Tree{
	struct Node{
		int l,r,s,v1,v2;
		ll lazy,sum;
	}tr[maxn<<3];
	int pos[maxn];
	
	inline void build(int i,int lf,int rf){
		tr[i].l=lf,tr[i].r=rf,tr[i].s=rf-lf+1;
		if(lf==rf){
			pos[lf]=i;
			return;
		}
		int mid=(lf+rf)>>1;
		build(i<<1,lf,mid),build(i<<1|1,mid+1,rf);
	}
	inline void pushdown(int i){
		if(tr[i].lazy){
			tr[i<<1].v1=tr[i<<1].v2=tr[i<<1].lazy=tr[i].lazy,tr[i<<1].sum=tr[i<<1].s*tr[i].lazy;
			tr[i<<1|1].v1=tr[i<<1|1].v2=tr[i<<1|1].lazy=tr[i].lazy,tr[i<<1|1].sum=tr[i<<1|1].s*tr[i].lazy;
			tr[i].lazy=0;
		}
	}
	inline void update(int i){
		tr[i].sum=tr[i<<1].sum+tr[i<<1|1].sum;
		tr[i].v1=tr[i<<1].v1,tr[i].v2=tr[i<<1|1].v2;
	}
	inline void fix(int i,ll z){
		tr[i].lazy=z,tr[i].sum=z*tr[i].s;
		tr[i].v1=tr[i].v2=z;
	}
	inline void modify(int i,int x,int y,int z){
		if(tr[i].v2>=z||tr[i].r<x||tr[i].l>y) return;
		if(tr[i].l>=x&&tr[i].r<=y&&tr[i].v1<=z){//>z<z 
			fix(i,z);
			return;
		}
		pushdown(i);
		modify(i<<1,x,y,z),modify(i<<1|1,x,y,z);
		update(i);
	}
	inline ll query(int i,int x,int y){
		if(tr[i].l>y||tr[i].r<x) return 0;
		if(tr[i].l>=x&&tr[i].r<=y) return tr[i].sum;
		pushdown(i);
		return query(i<<1,x,y)+query(i<<1|1,x,y);
	}
}
using namespace Segment_Tree;

int main(){
	rd(n);
	for(int i=1;i<=n;i++){
		rd(x);
		if(!p1[x]) p1[x]=i;
		else if(!p2[x]) p2[x]=i;
		p3[x]=p4[x],p4[x]=i;
		up=mx(up,x);
	}//p1,p2,p3,p4 
	for(int i=1;i<=up;i++){
		if(!p1[i]) p1[i]=inf;
		if(!p2[i]) p2[i]=inf;
	}//min 
	for(int i=1;i<=up;i++){
		for(int j=i<<1;j<=up;j+=i){
			p2[i]=mn(mx(p1[i],p1[j]),mn(p2[i],p2[j]));
			p1[i]=mn(p1[i],p1[j]);
			p3[i]=mx(mn(p4[i],p4[j]),mx(p3[i],p3[j]));
			p4[i]=mx(p4[i],p4[j]);
		}
	}//p1,p2,p3,p4 
	for(int i=1;i<=up;i++){
		if(!p3[i]) continue;// 
		if(p3[i]>1) q1[1].push_back(p3[i]-1),q2[1].push_back(i);
		if(p2[i]<n) q1[p2[i]+1].push_back(n),q2[p2[i]+1].push_back(i);
		if(p1[i]+1<p4[i]) q1[p1[i]+1].push_back(p4[i]-1),q2[p1[i]+1].push_back(i);
	}//ii 
	
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=q1[i].size()-1;~j;j--) modify(1,i,q1[i][j],q2[i][j]);
		ans+=query(1,i,n);
	}
	cout<<ans;
}