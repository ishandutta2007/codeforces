#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	int left,right,size;
}t[600000];

int n;
int a[200005],b[200005],sa[200005],sb[200005],s[200005],ans[200005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void build(int id,int l,int r,int x){
	t[id].left=l,t[id].right=r;
	if(l==r) return (void)(t[id].size=x);
	int mid=(l+r)/2;
	build(id<<1,l,mid,x);
	build(id<<1|1,mid+1,r,x);
	t[id].size=t[id<<1].size+t[id<<1|1].size;
}

int query(int id,int x){
	if(t[id].left==t[id].right) return t[id].size;
	if(x<=t[id<<1].right) return query(id<<1,x);
	else return query(id<<1|1,x)+t[id<<1].size;
}

void change(int id,int x,int c){
	if(t[id].left==t[id].right) return (void)(t[id].size=c);
	if(x<=t[id<<1].right) change(id<<1,x,c);
	else change(id<<1|1,x,c);
	t[id].size=t[id<<1].size+t[id<<1|1].size;
}

int find(int id,int x){
	if(t[id].left==t[id].right) return t[id].left;
	if(x<=t[id<<1].size) return find(id<<1,x);
	else return find(id<<1|1,x-t[id<<1].size);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint()+1;
	for(int i=1;i<=n;i++) b[i]=readint()+1;
	build(1,1,n,0);
	for(int i=n;i>=1;i--){
		sa[i]=query(1,a[i]);
		change(1,a[i],1);
	}
	build(1,1,n,0);
	for(int i=n;i>=1;i--){
		sb[i]=query(1,b[i]);
		change(1,b[i],1);
	}
	for(int i=n;i>=1;i--){
		s[i]+=sa[i]+sb[i];
		if(s[i]>=n-i+1) s[i]-=n-i+1,s[i-1]++;
	}
	build(1,1,n,1);
	for(int i=1;i<=n;i++){
		ans[i]=find(1,s[i]+1);
		change(1,ans[i],0);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]-1);
	printf("\n");
	return 0;
}