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
	int val,maxa;
}t[2200000];

const int N=1000005;
int n,m,q;
int a[300005],b[300005];

void change(int id,int l,int r,int p,int c){
	if(l==r){
		t[id].val+=c,t[id].maxa=t[id].val;
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) change(id<<1,l,mid,p,c);
	else change(id<<1|1,mid+1,r,p,c);
	t[id].val=t[id<<1].val+t[id<<1|1].val;
	t[id].maxa=max(t[id<<1|1].maxa,t[id<<1|1].val+t[id<<1].maxa);
}

int query(int id,int l,int r,int x){
	if(t[id].maxa+x<=0) return -1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(t[id<<1|1].maxa+x>0) return query(id<<1|1,mid+1,r,x);
	else return query(id<<1,l,mid,x+t[id<<1|1].val);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	for(int i=1;i<=n;i++) change(1,1,N,a[i],1);
	for(int i=1;i<=m;i++) change(1,1,N,b[i],-1);
	q=readint();
	int opt,x,y;
	for(int i=1;i<=q;i++){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) change(1,1,N,a[x],-1),change(1,1,N,y,1),a[x]=y;
		else change(1,1,N,b[x],1),change(1,1,N,y,-1),b[x]=y;
		printf("%d\n",query(1,1,N,0));
	}
	return 0;
}