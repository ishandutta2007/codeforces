#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;

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
int a[N],r[N],s[N];
int st[2][N],top[2]; 
void Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i+=2) a[i]=-a[i];
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	st[0][top[0]=0]=st[1][top[1]=0]=n+1;
	//
	for (int i=n;i>=1;i--)
	if (i&1)
	{
		while (top[1]&&s[st[1][top[1]]]>=s[i]) top[1]--;
		st[1][++top[1]]=i;
		r[i]=min(
		st[1][lower_bound(st[1]+1,st[1]+1+top[1],s[i-1],[&](int x,int y){return s[x]<y;})-st[1]-1],
		st[0][lower_bound(st[0]+1,st[0]+1+top[0],s[i-1],[&](int x,int y){return s[x]>y;})-st[0]-1]
		);
	}
	else
	{
		while (top[0]&&s[st[0][top[0]]]<=s[i]) top[0]--;
		st[0][++top[0]]=i;
	}
	//
	for (int i=1;i<=n;i++) a[i]=-a[i];
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	st[0][top[0]=0]=st[1][top[1]=0]=n+1;
	//
	for (int i=n;i>=1;i--)
	if (~i&1)
	{
		while (top[1]&&s[st[1][top[1]]]>=s[i]) top[1]--;
		st[1][++top[1]]=i;
		r[i]=min(
		st[1][lower_bound(st[1]+1,st[1]+1+top[1],s[i-1],[&](int x,int y){return s[x]<y;})-st[1]-1],
		st[0][lower_bound(st[0]+1,st[0]+1+top[0],s[i-1],[&](int x,int y){return s[x]>y;})-st[0]-1]
		);
	}
	else
	{
		while (top[0]&&s[st[0][top[0]]]<=s[i]) top[0]--;
		st[0][++top[0]]=i;
	}
	//
//	for (int i=1;i<=n;i++) print(r[i],",\n"[i==n]);
	int ans=0;
	map<int,vector<int>>mp;
	for (int i=n;i>=1;i--)
	{
		mp[s[i]].push_back(i);
		ans+=mp[s[i-1]].end()-upper_bound(mp[s[i-1]].begin(),mp[s[i-1]].end(),r[i],greater<int>());
//		print(ans);
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}