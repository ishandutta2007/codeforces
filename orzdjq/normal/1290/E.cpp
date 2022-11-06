#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#ifndef MY
	#define putchar IO::_putchar
	#define getchar IO::_getchar
#endif
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
const int Maxn=150005;
LL bit[Maxn];
void Add(int pos){
	while(pos<Maxn){
		bit[pos]++;
		pos+=pos&-pos;
	} 
}
LL Query(int pos){
	LL ret=0;
	while (pos){
		ret+=bit[pos];
		pos-=pos&-pos;
	} 
	return ret;
} 
LL Ans; 
struct node{
	int Mx1,Mx2,cnt,tag;
	LL Sum;
	node(){
		Mx1=Mx2=0;cnt=-1;Sum=0;
		tag=-1145141919; 
	}
	node(int Val){
		Mx1=Val;Mx2=-1e9;cnt=1;tag=-1145141919;
		Sum=Val;
	}
}Ept;
struct AngelBeats{
	node tree[Maxn*4];
	void Set(int p,int val,int t=0){
		if (t && val>0){
			LL dt=Query(tree[p].Mx1-1)-Query(val-1);
			Ans-=dt*tree[p].cnt;
		}
		if (t&&val<0){
			LL dt=Query(-val)-Query(-tree[p].Mx1);
			Ans-=dt*tree[p].cnt;
		}
		LL dlt=val-tree[p].Mx1;
		tree[p].Sum+=dlt*tree[p].cnt;
		tree[p].Mx1=val;
		
	}
	void push_down(int p){
		if (tree[p].tag!=-1145141919){
			if (tree[p*2].cnt!=-1 && tree[p*2].Mx1>tree[p].tag){
				Set(p*2,tree[p].tag);
				tree[p*2].tag=tree[p].tag;
			}
			if (tree[p*2+1].cnt!=-1 && tree[p*2+1].Mx1>tree[p].tag){
				Set(p*2+1,tree[p].tag);
				tree[p*2+1].tag=tree[p].tag;
			}
			tree[p].tag=-1145141919;
		}
	}
	void push_up(int p){
		if (tree[p*2].cnt==-1){
			tree[p]=tree[p*2+1];
			return;
		}
		if(tree[p*2+1].cnt==-1){
			tree[p]=tree[p*2]; 
			return;
		}
		if (tree[p*2].Mx1==tree[p*2+1].Mx1){
			tree[p].Mx1=tree[p*2].Mx1;
			tree[p].cnt=tree[p*2].cnt+tree[p*2+1].cnt;
			tree[p].Mx2=max(tree[p*2].Mx2,tree[p*2+1].Mx2);
		}
		else if (tree[p*2].Mx1<tree[p*2+1].Mx1){
			tree[p].Mx1=tree[p*2+1].Mx1;
			tree[p].cnt=tree[p*2+1].cnt;
			tree[p].Mx2=max(tree[p*2+1].Mx2,tree[p*2].Mx1);
		}
		else{
			tree[p].Mx1=tree[p*2].Mx1;
			tree[p].cnt=tree[p*2].cnt;
			tree[p].Mx2=max(tree[p*2].Mx2,tree[p*2+1].Mx1);
		}
		tree[p].Sum=tree[p*2].Sum+tree[p*2+1].Sum;
	}
	void SetVal(int p,int l,int r,int pos,int val){
		if (l==r){
			tree[p]=node(val);
			return;
		}
		push_down(p);
		int mid=l+r>>1;
		if (pos<=mid){
			SetVal(p*2,l,mid,pos,val);
		}
		else{
			SetVal(p*2+1,mid+1,r,pos,val);
		}
		push_up(p);
	}
	void modify(int p,int l,int r,int lo,int hi,int val){
		if (lo>hi) return;
		if (tree[p].cnt==-1 || val>=tree[p].Mx1) return;
		if (lo<=l && r<=hi){
			if (val>tree[p].Mx2){
				Set(p,val,1);
				tree[p].tag=val;
				return;
			}
		}
		if(l==r) return;
		push_down(p);
		int mid=l+r>>1;
		if (lo<=mid){
			modify(p*2,l,mid,lo,min(hi,mid),val);
		}
		if (hi>mid){
			modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
		}
		push_up(p); 
	} 
}L,R; 
int n,A[Maxn];
int pos[Maxn];
int main(){
	n=read();
	for (int i=1;i<=n;i++) A[i]=read();
	for (int i=1;i<=n;i++) pos[A[i]]=i;
	Ans=0;
	for (int i=1;i<=n;i++){
		//Set i to be available
		int p=pos[i];
		R.SetVal(1,1,n,p,n+1);
		L.SetVal(1,1,n,p,0); //negative
		Ans+=i;
		R.modify(1,1,n,1,p-1,p);
		L.modify(1,1,n,p+1,n,-p);
		Add(p);
		//LL Sr=R.tree[1].Sum+L.tree[1].Sum;
		//Sr-=i;
		printf("%lld\n",Ans);
	}
	return ~~(0^_^0);
}