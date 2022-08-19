#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y,id;
	bool operator<(const node c)const{return y<c.y;}
}q[100005];

const int N=100005;
int n,m;
int a[100005],s[100005],tag[300000],k[100005],b[100005],ans[100005];

int val(int x,int p){return x?p*k[x]+b[x]:1<<30;}

void change(int id,int l,int r,int c){
	if(!tag[id]) return (void)(tag[id]=c);
	if(l==r){
		if(val(c,l)<val(tag[id],l)) tag[id]=c;
		return;
	}
	int mid=(l+r)/2;
	if(k[c]>k[tag[id]]){
		if(val(c,mid)<val(tag[id],mid)) change(id<<1|1,mid+1,r,tag[id]),tag[id]=c;
		else change(id<<1,l,mid,c);
	}
	else{
		if(val(c,mid)<val(tag[id],mid)) change(id<<1,l,mid,tag[id]),tag[id]=c;
		else change(id<<1|1,mid+1,r,c);
	}
}

void update(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return change(id,l,r,c);
	int mid=(l+r)/2;
	if(qr<=mid) update(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) update(id<<1|1,mid+1,r,ql,qr,c);
	else update(id<<1,l,mid,ql,mid,c),update(id<<1|1,mid+1,r,mid+1,qr,c);
}

int query(int id,int l,int r,int x){
	if(l==r) return val(tag[id],x);
	int mid=(l+r)/2;
	if(x<=mid) return min(val(tag[id],x),query(id<<1,l,mid,x));
	else return min(val(tag[id],x),query(id<<1|1,mid+1,r,x));
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	m=readint();
	for(int i=1;i<=m;i++) q[i].x=readint(),q[i].y=readint(),q[i].id=i;
	sort(q+1,q+m+1);
	int now=1;
	for(int i=1;i<=m;i++){
		while(now<=q[i].y) k[now]=-a[now],b[now]=(now+1)*a[now]-s[now],update(1,1,N,1,now,now),now++;
		ans[q[i].id]=query(1,1,N,q[i].y-q[i].x+1)+s[q[i].y];
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}