#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define int long long
#define ri register
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define is insert
#define es erase
using namespace std; const int N=510;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
	return s*w;
}
int n,m;
char s[N][N];
inline void Output()
{
	for(ri int i=1;i<=n;i++) printf("%s\n",s[i]+1);
}
signed main()
{
	for(ri int T=read();T;T--)
	{
		n=read(), m=read();
		for(ri int i=1;i<=n;i++) scanf("%s",s[i]+1);
		if(n==1)
		{
			for(ri int i=1;i<=m;i++) s[1][i]='X';
			Output();
			continue;
		}
		int now=2;
		while(now<=n)
		{
			for(ri int i=1;i<=m;i++) s[now][i]='X';
			if(now>2)
			{
				int flg=0;
				for(ri int i=1;i<=m;i++) if(s[now-1][i]=='X'&&s[now-2][i]=='X') { flg=1; break; }
				if(flg) { now+=3; continue; }
				flg=0;
				for(ri int i=1;i<=m;i++)
				{
					if(s[now-1][i]=='X'||s[now-2][i]=='X')
					{
						s[now-1][i]=s[now-2][i]='X';
						flg=1;
						break;
					}
				}
				if(!flg) s[now-1][1]=s[now-2][1]='X';
			}
			now+=3;
		}
		if(now==n+1&&n>=2)
		{
			for(ri int i=1;i<=m;i++) if(s[n][i]=='X') s[n-1][i]='X';
		}
		Output();
	}
	return 0;
}