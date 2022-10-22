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
int n,a1[M],a2[M];
char s1[M];

signed main()
{
	WT
	{
		cin>>n>>s1+1;
		int cnt1=0;
		for (int i=1;i<=n;i++)
			if (s1[i]=='1')
				cnt1++;
		if (cnt1&1){NO continue;}
		int cnt2=0;
		for (int i=1;i<=n;i++)
			if (s1[i]=='1')
			{
				cnt2++;
				if (cnt2<=cnt1/2)a1[i]=a2[i]=1;
				else a1[i]=a2[i]=2;
			}
		int cnt3=0,cnt4=0,f=1,tmp=0;
		for (int i=1;i<=n;i++)
		{
			if (s1[i]=='1')
			{
				if (a1[i]==1)cnt3++,cnt4++;
				else cnt3--,cnt4--;
				if (cnt3<0||cnt4<0)
				{
					f=0;break;
				}
				continue;
			}
			if (tmp)
				a1[i]=1,a2[i]=2,cnt3++,cnt4--;
			else a1[i]=2,a2[i]=1,cnt3--,cnt4++;
			tmp^=1;
			if (cnt3<0||cnt4<0)
			{
				f=0;break;
			}
		}
		if (!f)NO
		else
		{
			YES
			for (int i=1;i<=n;i++)
				if (a1[i]==1)cout<<"(";
				else cout<<")";
			puts("");
			for (int i=1;i<=n;i++)
				if (a2[i]==1)cout<<"(";
				else cout<<")";
			puts("");
		}
	}
	return 0;
}/*
3
6
101101

*/