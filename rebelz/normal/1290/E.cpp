// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int ad[600000],num[600000],cur[600000],max1[600000],max2[600000],tag[600000],a[150005],pos[150005];
ll sum[600000],ans[150005];

void build(int id,int l,int r){
	ad[id]=sum[id]=num[id]=cur[id]=max1[id]=max2[id]=0,tag[id]=n+1;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void update(int id){
	max1[id]=max(max1[id<<1],max1[id<<1|1]);
	max2[id]=0,num[id]=0;
	if(max1[id]==max1[id<<1]) num[id]+=num[id<<1],chkmax(max2[id],max2[id<<1]);
	else chkmax(max2[id],max1[id<<1]);
	if(max1[id]==max1[id<<1|1]) num[id]+=num[id<<1|1],chkmax(max2[id],max2[id<<1|1]);
	else chkmax(max2[id],max1[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
	cur[id]=cur[id<<1]+cur[id<<1|1];
}

void add(int id,int c){
	ad[id]+=c,sum[id]+=1ll*c*cur[id];
	if(max1[id]) max1[id]+=c;
	if(max2[id]) max2[id]+=c;
}

void cmin(int id,int c){
	if(c>=max1[id]) return;
	chkmin(tag[id],c-ad[id]),sum[id]+=(c-max1[id])*num[id],chkmin(max1[id],c);
}

void pushdown(int id){
	if(tag[id]<=n) cmin(id<<1,tag[id]),cmin(id<<1|1,tag[id]),tag[id]=n+1;
	if(ad[id]) add(id<<1,ad[id]),add(id<<1|1,ad[id]),ad[id]=0;
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return add(id,c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

void getmin(int id,int l,int r,int ql,int qr,int c){
	if(c>=max1[id]) return;
	if(l==ql&&r==qr&&c>max2[id]) return cmin(id,c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) getmin(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) getmin(id<<1|1,mid+1,r,ql,qr,c);
	else getmin(id<<1,l,mid,ql,mid,c),getmin(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

void modify(int id,int l,int r,int x,int c){
	if(l==r) return (void)(max1[id]=sum[id]=c,max2[id]=0,num[id]=cur[id]=1);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	update(id);
}

namespace bit{
	int val[150005];
	void add(int x){for(;x<=n;x+=(x&(-x))) val[x]++;}
	int ask(int x){int ret=0; for(;x;x-=(x&(-x))) ret+=val[x]; return ret;}
}

void work1(){
	for(int i=1;i<=n;i++) pos[a[i]]=i;
	build(1,1,n);
	for(int i=1;i<=n;i++) bit::val[i]=0;
	for(int i=1;i<=n;i++){
		int pl=bit::ask(pos[i])+1;
		bit::add(pos[i]);
		change(1,1,n,pos[i],n,1);
		getmin(1,1,n,1,pos[i],pl);
		modify(1,1,n,pos[i],i+1);
		ans[i]+=sum[1];
	}
}

void work2(){
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) pos[a[i]]=i;
	build(1,1,n);
	for(int i=1;i<=n;i++) bit::val[i]=0;
	for(int i=1;i<=n;i++){
		int pl=bit::ask(pos[i])+1;
		bit::add(pos[i]);
		change(1,1,n,pos[i],n,1);
		getmin(1,1,n,1,pos[i],pl);
		modify(1,1,n,pos[i],i+1);
		ans[i]-=1ll*i*(i+1)-sum[1];
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	work1();
	work2();
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]-i);
	return 0;
}