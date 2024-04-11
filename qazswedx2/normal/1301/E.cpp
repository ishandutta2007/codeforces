#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,f[505][505][4],mp[1005],a[505][505],st[2005][505][12];
int sum[10000005],ls[10000005],rs[10000005],cnt,lg[100005];
int rt[1000005];
char s[1005][1005];
bool tcheck(int x,int y,int xx,int yy,int k)
{
	if(x<=0||y<=0||xx>n||yy>m) return 0;
	return f[xx][yy][k]-f[xx][y-1][k]-f[x-1][yy][k]+f[x-1][y-1][k]==(xx-x+1)*(yy-y+1);
}
bool check(int x,int y,int k)
{
	if(!k) return 1;
	int q1,q2,q3,q4;
	q1=tcheck(x-k+1,y-k+1,x,y,0);
	q2=tcheck(x-k+1,y+1,x,y+k,1);
	q3=tcheck(x+1,y-k+1,x+k,y,2);
	q4=tcheck(x+1,y+1,x+k,y+k,3);
	return q1&&q2&&q3&&q4;
}
/*void tpushup(int x)
{
	sum[x]=max(sum[ls[x]],sum[rs[x]]);
}
int tbuild(int tx,int txx,int l,int r)
{
	int x=++cnt;
	if(l==r)
	{
		sum[x]=0;
		for(int i=tx;i<=txx;i++)
			sum[x]=max(sum[x],a[i][l]);
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=tbuild(tx,txx,l,mid);
	rs[x]=tbuild(tx,txx,mid+1,r);
	tpushup(x);
//	printf("tx=%d,txx=%d,l=%d,r=%d,sum=%d,%d\n",tx,txx,l,r,sum[x],x);
	return x;
}
int tquery(int x,int l,int r,int ql,int qr)
{
//	printf("x=%d,l=%d,r=%d,ql=%d,qr=%d\n",x,l,r,ql,qr);
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2,q1,q2;
	q1=tquery(ls[x],l,mid,ql,qr);
	q2=tquery(rs[x],mid+1,r,ql,qr);
	return max(q1,q2);
}*/
int tquery(int x,int l,int r)
{
	int tnw=lg[r-l+1];
	return max(st[x][l][tnw],st[x][r-(1<<tnw)+1][tnw]);
}
void build(int x,int l,int r)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=l;j<=r;j++)
		{
			st[x][i][0]=max(st[x][i][0],a[j][i]);
		}
	}
	for(int i=1;i<=9;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
		{
			st[x][j][i]=max(st[x][j][i-1],st[x][j+(1<<(i-1))][i-1]);
			//if(i<=2)printf("x=%d,l=%d,r=%d,i=%d,j=%d,st=%d\n",x,l,r,i,j,st[x][j][i]);
		}
	if(l==r) return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
int query(int x,int l,int r,int ql,int qr,int tql,int tqr)
{
	if(ql>qr||tql>tqr) return 0;
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) 
	{
		int ans=tquery(x,tql,tqr);
		//printf("x=%d,l=%d,r=%d,ql=%d,qr=%d,tql=%d,tqr=%d,q=%d\n",x,l,r,ql,qr,tql,tqr,ans);
		return ans;
	}
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr,tql,tqr);
	q2=query(x*2+1,mid+1,r,ql,qr,tql,tqr);
//	if(x==1) printf("ql=%d,qr=%d,tql=%d,tqr=%d,q=%d\n",ql,qr,tql,tqr,max(q1,q2));
	return max(q1,q2);
}
int main()
{
	mp['R']=0,mp['G']=1,mp['Y']=2,mp['B']=3;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++)
				if(mp[s[i][j]]==k) f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k]+1;
				else f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(s[i][j]=='R'&&s[i][j+1]=='G'&&s[i+1][j]=='Y'&&s[i+1][j+1]=='B')
			{
				int nw=i;
				while(nw>1&&s[nw-1][j]=='R') nw--;
				int l=0,r=i-nw+1,mid;
				while(l<=r)
				{
					mid=(l+r)/2;
					if(check(i,j,mid)) l=mid+1;
					else r=mid-1;
				}
				a[i][j]=r;
				//printf("i=%d,j=%d,r=%d\n",i,j,r);
			}
	lg[1]=0;
	for(int i=2;i<=1000;i++)
		lg[i]=lg[i/2]+1;
	build(1,1,n);
	//printf("ct=%d\n",cnt);
	for(int i=1;i<=q;i++)
	{
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		int l=0,r=(xx-x+1)/2;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((!mid)||query(1,1,n,x+mid-1,xx-mid,y+mid-1,yy-mid)>=mid) l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r*r*4);
	}
	return 0;
}