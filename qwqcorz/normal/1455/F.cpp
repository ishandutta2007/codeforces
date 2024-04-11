#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;

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
int n,k;
char a[N];
char get(char x)
{
	if (x=='a') return x;
	if (x-'a'+1==k) return 'a';
	return x-1;
}
string X(char x){string str="";str+=x;return str;}
string dp[N][2];
int from[N][2];
void output(int x,int y)
{
	if (x>3) output(x-1,from[x][y]);
	putchar(dp[x][y][0]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		n=read(),k=read();
		scanf("%s",a+1);
		if (n==1)
		{
			putchar(get(a[1]));
			putchar('\n');
			continue;
		}
		if (n==2)
		{
			puts(min(X(get(a[1]))+X(get(a[2])),min(X(get(a[2]))+X(a[1]),X(a[2])+X(get(a[1])))).c_str());
			continue;
		}
		dp[1][0]=X(get(a[1]))+X(a[2]);
		dp[1][1]=X(a[2])+X(a[1]);
//		puts(dp[1][0].c_str());
//		puts(dp[1][1].c_str());
		dp[2][0]=min(X(get(a[1]))+X(get(a[2])),min(X(get(a[2]))+X(a[1]),X(a[2])+X(get(a[1]))))+X(a[3]);
		dp[2][1]=dp[1][0]+X(a[3]),swap(dp[2][1][1],dp[2][1][2]);
//		puts(dp[2][0].c_str());
//		puts(dp[2][1].c_str());
		for (int i=3;i<=n;i++)
		{
			char x='a',y='a';
			string tmp[2]={dp[i-1][0],dp[i-1][1]};
			if (i>3) x=tmp[0][0],y=tmp[1][0],tmp[0].erase(0,1),tmp[1].erase(0,1);
			from[i][0]=from[i][1]=0;
			if (x<=y)
			{
				dp[i][0]=min(X(tmp[0][0])+X(tmp[0][2])+X(tmp[0][1]),X(tmp[0][0])+X(tmp[0][1])+X(get(tmp[0][2])));
				string st=min(min(X(tmp[1][1])+X(tmp[1][0])+X(tmp[1][2]),
								  X(tmp[1][0])+X(tmp[1][2])+X(tmp[1][1])),
								  X(tmp[1][0])+X(get(tmp[1][1]))+X(tmp[1][2]));
				if (x==y&&st<dp[i][0]) dp[i][0]=st,from[i][0]=1;
				dp[i][0]+=a[i+1];
			}
			else dp[i][0]=min(min(X(tmp[1][1])+X(tmp[1][0])+X(tmp[1][2]),
								  X(tmp[1][0])+X(tmp[1][2])+X(tmp[1][1])),
								  X(tmp[1][0])+X(get(tmp[1][1]))+X(tmp[1][2])),
				 from[i][0]=1;
			
			dp[i][1]=X(tmp[0][0])+X(tmp[0][1])+X(a[i+1])+X(tmp[0][2]);
//		puts(dp[i][0].c_str());
//		puts(dp[i][1].c_str());
		}
		output(n,0);
		putchar(dp[n][0][1]);
		putchar(dp[n][0][2]);
		putchar('\n');
	}
	
	return 0;
}
/*
1
7 4
dcdbdaa
*/