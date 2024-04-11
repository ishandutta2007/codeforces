#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=110;
int T,n;string s;
int a[M],k[M];

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;n=s.size();bool f=0;
		for (int i=1;i<=n;i++)a[i]=s[i-1]-'0';
		for (int i=1;i<=n+1;i++)
		{
			int cnt=0;bool ff=1;
			for (int j=1;j<i;j++)
				if (a[j]==1)k[++cnt]=j;
			for (int j=i;j<=n;j++)
				if (a[j]==0)k[++cnt]=j;
			for (int j=2;j<=cnt;j++)
				if (k[j]-k[j-1]<=1)ff=0;
			if (ff)f=1;//,cout<<i<<' ';
			
		}
		if (f)puts("YES");
		else puts("NO");
	}
	return 0;
}