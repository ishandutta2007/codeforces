#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int base=27;
int n;string s;
map<int,int>t;

signed main()
{
	WT
	{
		n=read();cin>>s;t.clear();
		for (int i=0;i<n;i++)
			for (int j=i;j<=i+2&&j<n;j++)
			{
				int hash=0;
				for (int k=i;k<=j;k++)
					hash=hash*base+(s[k]-'a'+1);
				t[hash]=1;
			}int f=0;
		for (int i=1;i<=26;i++)
			if (!t[i])
			{
				cout<<char(i+'a'-1)<<endl;
				f=1;break;
			}
		if (f)continue;
		for (int i=1;i<=26;i++)
		{
			for (int j=1;j<=26;j++)
				if (!t[i*base+j])
				{
					cout<<char(i+'a'-1)<<char(j+'a'-1)<<endl;
					f=1;break;
				}
			if (f)break;
		}
		if (f)continue;
		for (int i=1;i<=26;i++)
		{
			for (int j=1;j<=26;j++)
			{
				for (int k=1;k<=26;k++)
					if (!t[i*base*base+j*base+k])
					{
						cout<<char(i+'a'-1)<<(char)(j+'a'-1)<<(char)(k+'a'-1)<<endl;
						f=1;break;
					}
				if (f)break;
			}if (f)break;
		}
		if (f)continue;
	}
	return 0;
}