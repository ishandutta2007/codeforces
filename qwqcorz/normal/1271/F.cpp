#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[2][3],d[8],t[2][3],ans[8];
bool solve()
{
	memcpy(t,a,sizeof(t));
	for (int j=0;j<3;j++) t[0][j]+=t[1][j];
	for (int i=1;i<=7;i++)
	for (int j=0;j<3;j++)
	if (i>>j&1) t[0][j]-=d[i];
	for (int j=0;j<3;j++) if (t[0][j]<0) return 0;
	for (int i=0;i<=d[3]&&i<=a[0][0]&&i<=a[0][1];i++)
	for (int j=0;j<=d[5]&&i+j<=a[0][0]&&j<=a[0][2];j++)
	for (int k=0;k<=d[6]&&i+k<=a[0][1]&&j+k<=a[0][2];k++)
	{
		t[0][0]=a[0][0]-i-j;
		t[0][1]=a[0][1]-i-k;
		t[0][2]=a[0][2]-j-k;
		if ((t[1][0]=a[1][0]-(d[3]-i)-(d[5]-j))<0) continue;
		if ((t[1][1]=a[1][1]-(d[3]-i)-(d[6]-k))<0) continue;
		if ((t[1][2]=a[1][2]-(d[5]-j)-(d[6]-k))<0) continue;
		if (min({t[0][0],t[0][1],t[0][2]})+min({t[1][0],t[1][1],t[1][2]})>=d[7])
		{
			ans[3]=i;
			ans[5]=j;
			ans[6]=k;
			int tmp=ans[7]=min({t[0][0],t[0][1],t[0][2],d[7]});
			t[0][0]-=tmp,t[0][1]-=tmp,t[0][2]-=tmp;
			ans[1]=min(t[0][0],d[1]);
			ans[2]=min(t[0][1],d[2]);
			ans[4]=min(t[0][2],d[4]);
			for (int i=7;i>=1;i--) print(ans[i]," \n"[i==1]);
			return 1;
		}
	}
	return 0;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		for (int i=0;i<2;i++)
		for (int j=2;j>=0;j--) a[i][j]=read();
		for (int i=7;i>=1;i--) d[i]=read();
		if (!solve()) puts("-1");
	}
	
	return 0;
}