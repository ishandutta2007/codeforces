#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int cys=1000000007;

struct node{
	int left,right,sum;
}t[3000000];

int n;
int a[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void change(int id,int p,int c){
	if(t[id].left==t[id].right) return (void)(t[id].sum=c);
	if(p<=t[id<<1].right) change(id<<1,p,c);
	else change(id<<1|1,p,c);
	t[id].sum=(t[id<<1].sum+t[id<<1|1].sum)%cys;
}

int query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id].sum;
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	else return (query(id<<1,l,t[id<<1].right)+query(id<<1|1,t[id<<1|1].left,r))%cys;
}

int main(){
	n=readint();
	int maxa=0;
	for(int i=1;i<=n;i++) a[i]=readint(),maxa=max(maxa,a[i]);
	build(1,1,maxa);
	for(int i=1;i<=n;i++) change(1,a[i],(1ll*query(1,1,a[i])*a[i]%cys+a[i])%cys);
	printf("%d\n",t[1].sum);
	return 0;
}