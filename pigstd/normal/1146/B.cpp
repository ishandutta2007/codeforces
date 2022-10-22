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

const int M=1e5+10;
char s[M],ans[M],ans2[M];

signed main()
{
	cin>>s+1;int len=strlen(s+1),p=0;
	for (int i=len;i>=1;i--)
		if (s[i]=='a'){p=i;break;}
	int cnt1=0;
	for (int i=1;i<=p;i++)
		if (s[i]!='a')
			cnt1++;
	if (cnt1+p>len)return puts(":("),0;
	if ((len-(cnt1+p))&1)return puts(":("),0;
	int x=len-(cnt1+p);x/=2;x+=p;
	for (int i=1;i<=x;i++)
		ans[i]=ans2[i]=s[i];
	int cnt=x;
	for (int i=1;i<=x;i++)
		if (s[i]!='a')
			ans2[++cnt]=s[i];
	bool f=0;
	for (int i=1;i<=len;i++)
		if (ans2[i]!=s[i])f=1;
	if (f)return puts(":("),0;
	cout<<ans+1;
	return 0;
}