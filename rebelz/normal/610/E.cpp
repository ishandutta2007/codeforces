#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,lazy;
	int f[11][11];
}t[530000];

int n,m,k;
int g[11][11];
char s[200005];

void update(int id){
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) t[id].f[i][j]=t[id<<1].f[i][j]+t[id<<1|1].f[i][j];
	t[id].f[t[id<<1].r][t[id<<1|1].l]++;
	t[id].l=t[id<<1].l,t[id].r=t[id<<1|1].r;
}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].l=t[id].r=s[l]-'a'+1);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy=t[id<<1|1].lazy=t[id].lazy;
		t[id<<1].l=t[id<<1].r=t[id<<1|1].l=t[id<<1|1].r=t[id].lazy;
		memset(t[id<<1].f,0,sizeof(t[id<<1].f));
		memset(t[id<<1|1].f,0,sizeof(t[id<<1|1].f));
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		memset(t[id].f,0,sizeof(t[id].f));
		t[id].l=t[id].r=t[id].lazy=c;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

int main(){
	n=readint(); m=readint(); k=readint();
	scanf("%s",s+1);
	build(1,1,n);
	int opt,x,y; char z,w[11];
	for(int i=1;i<=m;i++){
		opt=readint();
		if(opt==1){
			x=readint(); y=readint(); z=getchar();
			while(z<'a'||z>'a'+k-1) z=getchar();
			change(1,1,n,x,y,z-'a'+1);
		}
		else{
			scanf("%s",w+1);
			int ans=n;
			memset(g,0,sizeof(g));
			for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++) g[w[i]-'a'+1][w[j]-'a'+1]=1;
			for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) ans-=t[1].f[i][j]*g[i][j];
			printf("%d\n",ans);
		}
	}
	return 0;
}