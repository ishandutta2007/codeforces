#include<bits/stdc++.h>
using namespace std;

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
int a[20],pw[20];
int check(int n){int ret=0;for (int i=1;i<=n;i++) ret+=a[i];return ret;}
void GunRose()
{
	int s=read(),n=read(),m=0;
	while (s) a[++m]=s%10,s/=10;
	while (check(m)<n) for (int i=2;i<=m;i++) if (a[i]){a[i]--,a[i-1]+=10;break;}
	int tot=check(m)-n+1,now=0;
	for (int i=m;i>=1;i--)
	{
		int tmp=min(a[i],tot);
		tot-=tmp,a[i]-=tmp;
		now+=tmp*pw[i-1];
	}
	print(now," \n"[!--n]);
	for (int i=1;i<=m;i++)
	for (int j=1;j<=a[i];j++)
	print(pw[i-1]," \n"[!--n]);
}

signed main()
{
	for (int i=pw[0]=1;i<=9;i++) pw[i]=pw[i-1]*10;
	int T=read();
	while (T--) GunRose();
	
	return 0;
}