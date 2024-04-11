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

const int M=1e6+10;
int k,cnt;
string s;
int len[M];

bool check(int x)
{
	int sum=0,ss=0,maxn=0;
	for (int i=1;i<=cnt;i++)
		maxn=max(maxn,len[i]);
	if (maxn>x)return 0;
	for (int i=1;i<=cnt;i++)
		if (sum+len[i]>x)sum=len[i],ss++;
		else sum+=len[i];
	if (sum!=0)ss++;
	return ss<=k;
}

signed main()
{
	cin>>k;
	while(cin>>s)
	{
		len[cnt]++;
		for (int i=0,l=0;i<s.size();i++)
		{
			if (s[i]=='-')len[++cnt]=i-l+1,l=i+1;
			if (i==s.size()-1)len[++cnt]=i-l+1;
		}
	}
//	for (int i=1;i<=cnt;i++)cout<<len[i]<<' ';
	int tl=1,tr=1e8,ans;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))tr=Mid-1,ans=Mid;
		else tl=Mid+1;
	}cout<<ans<<endl;
	return 0;
}