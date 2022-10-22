#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n;char s[M],ans[M];

signed main()
{
	WT
	{
		cin>>s+1;n=strlen(s+1);
		bool f=1;
		for (int i=1;i<=n;i++)
			if (s[i]!='a')f=0;
		if (f){NO continue;}
		YES
		for (int i=1;i<=n+1;i++)
		{
			if (n+2-i>i)
			{
				if (s[n+1-i]!='a')
				{
					for (int j=1;j<i;j++)
						cout<<s[j];
					cout<<'a';
					for (int j=i;j<=n;j++)
						cout<<s[j];
					break;
				}
			}
			if (n+2-i<i)
			{
				if (s[n+2-i]!='a')
				{
					for (int j=1;j<i;j++)cout<<s[j];
					cout<<'a';
					for (int j=i;j<=n;j++)
						cout<<s[j];
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}