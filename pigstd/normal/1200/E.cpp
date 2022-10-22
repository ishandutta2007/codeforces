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

const int M=1e5+10;
const int N=1e6+10;
int n,kmp[N];
string s[M],ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)cin>>s[i];
	ans=s[1];
	for (int i=1;i<n;i++)
	{
		string ss=" "+s[i+1];int l=min(s[i+1].size(),ans.size());
		for (int j=ans.size()-l;j<ans.size();j++)
			ss+=ans[j];
		int len=ss.size()-1,now=0,len2=s[i+1].size(),len1=ans.size();
		for (int j=2;j<=len;j++)
		{
			while(now>0&&ss[j]!=ss[now+1])now=kmp[now];
			if (ss[j]==ss[now+1])now++;
			kmp[j]=now;
		}
		while(now>min(len2,len1))now=kmp[now];
		for (int j=now;j<len2;j++)
			ans+=s[i+1][j];
	}cout<<ans<<endl;
	return 0;
}