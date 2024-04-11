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
int n,tmp,cnt1[M],cnt2[M];
char s1[M],s2[M];

signed main()
{
	WT
	{
		cin>>n>>s1+1>>s2+1;tmp=0;
		for (int i=1;i<=n;i++)
		{
			cnt1[i]=cnt1[i-1],cnt2[i]=cnt2[i-1];
			if (s1[i]=='1')cnt1[i]++;
			else cnt2[i]++;
		}bool f=0;
		for (int i=n;i>=0;i--)
		{
			int p=(s1[i]-'0')^(s2[i]-'0')^tmp;
			if (p==0)continue;
			if (cnt1[i]!=cnt2[i]){f=1;break;}
			tmp^=1;
		}
		if (f)NO
		else YES
	}
	return 0;
}