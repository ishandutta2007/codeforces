#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	int left,right,maxa;
}t[300000];

int n,s,g,ans;
int d[100005],maxa[20][100005],mina[20][100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int getmax(int l,int r){int k=0;for(;1<<k+1<r-l+1;k++);return max(maxa[k][l],maxa[k][r-(1<<k)+1]);}
int getmin(int l,int r){int k=0;for(;1<<k+1<r-l+1;k++);return min(mina[k][l],mina[k][r-(1<<k)+1]);}

void divide(int l,int r,int x){
	if(l>r) return;
	int mid=(l+r)/2;
	if(getmax(mid+1,x)-getmin(mid+1,x)>s) divide(mid+1,r,x);
	else ans=mid,divide(l,mid-1,x);
}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r,t[id].maxa=1<<30;
	if(l==r) return; int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void change(int id,int p,int c){
	if(t[id].left==p&&t[id].right==p) return (void)(t[id].maxa=c);
	if(p<=t[id<<1].right) change(id<<1,p,c);
	else change(id<<1|1,p,c);
	t[id].maxa=min(t[id<<1].maxa,t[id<<1|1].maxa);
}

int query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id].maxa;
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	else return min(query(id<<1,l,t[id<<1].right),query(id<<1|1,t[id<<1|1].left,r));
}

int main(){
	n=readint(); s=readint(); g=readint();
	if(g>n){printf("-1\n");return 0;}
	for(int i=1;i<=n;i++) mina[0][i]=maxa[0][i]=readint();
	for(int i=1;1<<i<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++) mina[i][j]=min(mina[i-1][j],mina[i-1][j+(1<<i-1)]),maxa[i][j]=max(maxa[i-1][j],maxa[i-1][j+(1<<i-1)]);
	build(1,1,n+1); change(1,1,0);
	for(int i=g;i<=n;i++){
		ans=-1; divide(0,i-g,i);
		if(ans==-1) d[i]=1<<30;
		else d[i]=query(1,ans+1,i-g+1)+1;
		change(1,i+1,d[i]);
	}
	if(d[n]>1<<29) printf("-1\n");
	else printf("%d\n",d[n]);
	return 0;
}