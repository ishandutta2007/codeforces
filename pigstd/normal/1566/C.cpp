//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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

string s1,s2;

signed main()
{
	WT
	{
		int n=read(),ans=0;
		cin>>s1>>s2;int F=0;
		for (int i=0;i<n;i++)
		{
			int x=s1[i]-'0',y=s2[i]-'0';
			if (x!=y)
			{
				if (F==1)ans++;
				F=0;ans+=2;
			}
			else
			{
				if (x==0)
				{
					if (F==1)ans++,F=1;
					else if (F==2)ans+=2,F=0;
					else F=1;
				}
				else
				{
					if (F==1)ans+=2,F=0;
					else F=2;
				}
			}
		}if (F==1)ans++;
		cout<<ans<<endl;
	}
	return 0;
}