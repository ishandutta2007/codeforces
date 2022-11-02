#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200010;
const int B=5;
#define rep(i,n) for(int i=1;i<=n;i++)
struct Matrix
{
	int a[B][B];
	friend Matrix operator +(const Matrix&a,const Matrix&b)
	{
		Matrix c;
		memset(c.a,0x3f,sizeof(c.a));
		for(int k=0;k<B;k++)for(int i=0;i<B;i++)for(int j=0;j<B;j++)c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
		return c;
	}
}tree[N<<2];
char s[N];
int n,q;
void build(int p,int le,int ri)
{
	if(le==ri)
	{
		memset(tree[p].a,0x3f,sizeof(tree[p].a));
		if(s[le]=='2')
		{
			tree[p].a[0][0]=1;
			tree[p].a[0][1]=0;
			tree[p].a[1][1]=0;
			tree[p].a[2][2]=0;
			tree[p].a[3][3]=0;
			tree[p].a[4][4]=0;
		}
		else if(s[le]=='0')
		{
			tree[p].a[0][0]=0;
			tree[p].a[1][1]=1;
			tree[p].a[1][2]=0;
			tree[p].a[2][2]=0;
			tree[p].a[3][3]=0;
			tree[p].a[4][4]=0;
		}
		else if(s[le]=='1')
		{
			tree[p].a[0][0]=0;
			tree[p].a[1][1]=0;
			tree[p].a[2][2]=1;
			tree[p].a[2][3]=0;
			tree[p].a[3][3]=0;
			tree[p].a[4][4]=0;
		}
		else if(s[le]=='7')
		{
			tree[p].a[0][0]=0;
			tree[p].a[1][1]=0;
			tree[p].a[2][2]=0;
			tree[p].a[3][3]=1;
			tree[p].a[3][4]=0;
			tree[p].a[4][4]=0;
		}
		else if(s[le]=='6')
		{
			tree[p].a[0][0]=0;
			tree[p].a[1][1]=0;
			tree[p].a[2][2]=0;
			tree[p].a[3][3]=1;
			tree[p].a[4][4]=1;
		}
		else
		{
			tree[p].a[0][0]=0;
			tree[p].a[1][1]=0;
			tree[p].a[2][2]=0;
			tree[p].a[3][3]=0;
			tree[p].a[4][4]=0;
		}
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	tree[p]=tree[p<<1]+tree[p<<1|1];
}
Matrix get(int p,int le,int ri,int ll,int rr)
{
	if(ll<=le&&ri<=rr)return tree[p];
	int mid=(le+ri)>>1;
	Matrix ans;
	memset(ans.a,0x3f,sizeof(ans.a));
	rep(i,B)ans.a[i-1][i-1]=0;
	if(ll<=mid)ans=ans+get(p<<1,le,mid,ll,rr);
	if(rr>mid)ans=ans+get(p<<1|1,mid+1,ri,ll,rr);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build(1,1,n);
	rep(i,q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		Matrix tmp=get(1,1,n,l,r);
		//printf("%d %d %d %d\n",tmp.a[0][1],tmp.a[0][2],tmp.a[0][3],tmp.a[0][4]);
		if(tmp.a[0][4]>n+100)puts("-1");
		else printf("%d\n",tmp.a[0][4]);
	}
	return 0;
}