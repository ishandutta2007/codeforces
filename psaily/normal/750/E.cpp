#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
char str[maxn];
int n,m;
#define N 5
struct matrix{
	int A[N][N];
	matrix(){memset(A,inf,sizeof(A));}
	matrix operator + (const matrix&_)const{
		matrix tmp;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
					tmp.A[i][j]=min(tmp.A[i][j],A[i][k]+_.A[k][j]);
		return tmp;
	}
};
struct segment_tree{
	struct node{
		int l,r;
	}tree[maxn<<2];
	matrix mat[maxn<<2];
	/*
		0 
		1 2
		2 20
		3 201
		4 2017
	*/
	void build(int p,int l,int r){
		tree[p].l=l,tree[p].r=r;
		if(l==r){
			for(int i=0;i<N;i++)mat[p].A[i][i]=0;
			if(str[l]=='2')mat[p].A[0][1]=0,mat[p].A[0][0]=1;
			if(str[l]=='0')mat[p].A[1][2]=0,mat[p].A[1][1]=1;
			if(str[l]=='1')mat[p].A[2][3]=0,mat[p].A[2][2]=1;
			if(str[l]=='7')mat[p].A[3][4]=0,mat[p].A[3][3]=1;
			if(str[l]=='6')mat[p].A[3][3]=1,mat[p].A[4][4]=1;
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		mat[p]=mat[p<<1]+mat[p<<1|1];
	}
	matrix query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mat[p];
		int mid=(l+r)>>1;
		if(qr<=mid)return query(p<<1,l,mid,ql,qr);
		else if(mid<ql)return query(p<<1|1,mid+1,r,ql,qr);
		else return query(p<<1,l,mid,ql,qr)+query(p<<1|1,mid+1,r,ql,qr);
	}
}T;
int main(){
	scanf("%d%d%s",&n,&m,str+1);
	T.build(1,1,n);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		matrix ans=T.query(1,1,n,l,r);
		printf("%d\n",ans.A[0][4]==inf?-1:ans.A[0][4]);
	}
	return 0;
}