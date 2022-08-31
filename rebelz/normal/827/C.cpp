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
	int left,right;
	int cnt[11][10][4];
}t[300000];

int n,q;
int a[100005],g[200];
char s[100005];

void update(int id){
	for(int i=1;i<=10;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<4;k++)
				t[id].cnt[i][j][k]=t[id<<1].cnt[i][j][k]+t[id<<1|1].cnt[i][(j-(t[id<<1].right-t[id<<1].left+1)%i+i)%i][k];
}

void build(int id,int l,int r){
	t[id].left=l,t[id].right=r;
	if(l==r){
		for(int i=1;i<=10;i++) t[id].cnt[i][0][a[l]]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void change(int id,int p,int c){
	if(t[id].left==t[id].right){
		for(int i=1;i<=10;i++) t[id].cnt[i][0][a[p]]=0;
		a[p]=c;
		for(int i=1;i<=10;i++) t[id].cnt[i][0][a[p]]=1;
		return;
	}
	if(p<=t[id<<1].right) change(id<<1,p,c);
	else change(id<<1|1,p,c);
	update(id);
}

node query(int id,int l,int r){
	if(t[id].left==l&&t[id].right==r) return t[id];
	if(t[id<<1].right>=r) return query(id<<1,l,r);
	else if(t[id<<1|1].left<=l) return query(id<<1|1,l,r);
	node lson=query(id<<1,l,t[id<<1].right),rson=query(id<<1|1,t[id<<1|1].left,r),ans;
	ans.left=lson.left,ans.right=rson.right;
	for(int i=1;i<=10;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<4;k++)
				ans.cnt[i][j][k]=lson.cnt[i][j][k]+rson.cnt[i][(j-(lson.right-lson.left+1)%i+i)%i][k];
	return ans;
}

int main(){
	g['A']=0,g['T']=1,g['G']=2,g['C']=3;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=g[s[i]];
	build(1,1,n);
	q=readint();
	int opt,x,y,ans,l; char c; char k[15];
	while(q--){
		opt=readint(); x=readint();
		if(opt==1){
			scanf("%c",&c);
			change(1,x,g[c]);
		}
		else{
			y=readint(); scanf("%s",k); l=strlen(k);
			node now=query(1,x,y); ans=0;
			for(int i=0;i<l;i++) ans+=now.cnt[l][i][g[k[i]]];
//			for(int i=0;i<l;i++) cout<<"TEST "<<now.cnt[l][i][g[k[i]]]<<' ';
//			cout<<endl;
			printf("%d\n",ans);
		}
	}
	return 0;
}