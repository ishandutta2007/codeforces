#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int A=35;
const int B=350;

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
char s[N];
int a[N],dp[N][A*2+5][B*2+5];
inline void up(int &x,int y) {
	x=min(x,y);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	memset(dp,0x3f,sizeof(dp));
	scanf("%s",s+1);
	int n=strlen(s+1)+1;
	for (int i=2;i<=n;i++) a[i]=s[i-1]-'0';
	dp[0][A][B]=0;
	for (int i=1;i<=n;i++)
	for (int j=-A;j<=A;j++)
	for (int k=-6*i;k<=6*i;k++)
	if (dp[i-1][j+A][k+B]<dp[0][0][0])
	for (int t=-6;t<=6;t++)
	{
		int tmp=j*10+a[i]+k+t;
		if (tmp>=-A&&tmp<=A) up(dp[i][tmp+A][k+t+B],dp[i-1][j+A][k+B]+abs(t)*(n-i+1));
	}
//	for (int i=1;i<=n;i++)
//	for (int j=-A;j<=A;j++)
//	for (int k=-6*i;k<=6*i;k++)
//	if (dp[i][j+A][k+B]<dp[0][0][0])
//	{
//		print(i,' ');
//		print(j,' ');
//		print(k,' ');
//		print(dp[i][j+A][k+B]);
//	}
	int ans=dp[0][0][0];
	for (int k=-6*n;k<=6*n;k++)
	up(ans,dp[n][A][k+B]);
	print(ans);
	
	return 0;
}