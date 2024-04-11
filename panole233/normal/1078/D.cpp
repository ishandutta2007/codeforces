#include<cstdio>
#include<cstring>

int n,L,R,lo[100001];
int fl[17][100001][17],fr[17][100001][17],x,y;

int getmin(int a,int b) {return a<b?a:b;}
int getmax(int a,int b) {return a>b?a:b;}
int nxt(int x,int y) {return (x+y-1)%n+1;}
int la(int x,int y) {return (x<=y)?((x-y)%n+n):((x-y-1)%n+1);}

int lgm(int l,int r,int j)
{
	int len=lo[r-l+1];
	return getmax(fl[j][l][len],fl[j][r-(1<<len)+1][len]);
}

int rgm(int l,int r,int j)
{
	int len=lo[r-l+1];
	return getmax(fr[j][l][len],fr[j][r-(1<<len)+1][len]);
}

int ljp(int l,int r,int x,int j)
{
	if (l<=r) return lgm(l,r,j)+x;
	int ans=lgm(1,r,j)+x-(x<=r?0:n);
	ans=getmax(ans,lgm(l,n,j)+x+(x<=r?n:0));
	return ans;
}

int rjp(int l,int r,int x,int j)
{
	if (l<=r) return rgm(l,r,j)-x;
	int ans=rgm(l,n,j)-x-(x>=l?0:n);
	ans=getmax(ans,rgm(1,r,j)-x+(x>=l?n:0));
	return ans;
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=100000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&x),fr[0][i][0]=x+i,fl[0][i][0]=x-i;
	if (n==1) {printf("0"); return 0;}
	for (int j=1; j<17; j++)
		for (int i=1; i<=n; i++)
			if (i+(1<<j)-1<=n)
				fl[0][i][j]=getmax(fl[0][i][j-1],fl[0][i+(1<<j-1)][j-1]),
				fr[0][i][j]=getmax(fr[0][i][j-1],fr[0][i+(1<<j-1)][j-1]);
	for (int j=1; j<17; j++)
	{ 
		for (int i=1; i<=n; i++) 
		{
			if (fl[j-1][i][0]+fr[j-1][i][0]>=n) fl[j][i][0]=n-i,fr[j][i][0]=n+i; else
			fl[j][i][0]=ljp(la(i,fl[j-1][i][0]+i),nxt(i,fr[j-1][i][0]-i),i,j-1)-i,
			fr[j][i][0]=rjp(la(i,fl[j-1][i][0]+i),nxt(i,fr[j-1][i][0]-i),i,j-1)+i;
		}
		for (int k=1; k<17; k++)
			for (int i=1; i<=n; i++)
				if (i+(1<<k)-1<=n)
					fl[j][i][k]=getmax(fl[j][i][k-1],fl[j][i+(1<<k-1)][k-1]),
					fr[j][i][k]=getmax(fr[j][i][k-1],fr[j][i+(1<<k-1)][k-1]);
	} 
	for (int i=1; i<=n; i++)
	{
		int ans=0; L=R=i;
		for (int j=16; j>=0; j--)
		{
			x=ljp(L,R,i,j); y=rjp(L,R,i,j);
			if (x+y<n-1) ans+=(1<<j),L=la(i,x),R=nxt(i,y);
		}
		printf("%d ",ans+1);
	}
	return 0;
}