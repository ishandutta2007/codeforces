#include<bits/stdc++.h>
using namespace std;
const int maxn=15000150;
int n,q,cnt,rt,ch[maxn][2],sum[maxn],same[maxn];
inline void pushup(int x){sum[x]=sum[ch[x][0]]+sum[ch[x][1]];}
inline void pushdown(int x,int l,int r){
	if(~same[x]){
		int mid=(l+r)>>1;
		if(!ch[x][0]) same[ch[x][0]=++cnt]=-1;
		if(!ch[x][1]) same[ch[x][1]=++cnt]=-1;
		same[ch[x][0]]=same[ch[x][1]]=same[x];
		sum[ch[x][0]]=(mid-l+1)*same[x];
		sum[ch[x][1]]=(r-mid)*same[x];
		same[x]=-1;
	}
}
void update(int &x,int l,int r,int ql,int qr,int v){
	if(!x) same[x=++cnt]=-1;
	if(l>=ql && r<=qr) return void(sum[x]=(same[x]=v)*(r-l+1));
	int mid=(l+r)>>1;pushdown(x,l,r);
	if(mid>=ql) update(ch[x][0],l,mid,ql,qr,v);
	if(mid<qr) update(ch[x][1],mid+1,r,ql,qr,v);
	pushup(x);
}
int main(){
	scanf("%d%d",&n,&q);
	update(rt,1,n,1,n,1);
	for(int i=1;i<=q;i++){
		int l,r,op;
		scanf("%d%d%d",&l,&r,&op);
		update(rt,1,n,l,r,op-1);
		printf("%d\n",sum[rt]);
	}
}