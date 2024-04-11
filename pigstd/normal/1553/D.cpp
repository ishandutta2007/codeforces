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

const int M=1e5+10;
int f[M];
string s1,s2;

signed main()
{
	WT
	{
		cin>>s1>>s2;int ff=0;
		for (int i=0;i*2<s1.size();i++)swap(s1[i],s1[s1.size()-i-1]);
		for (int i=0;i*2<s2.size();i++)swap(s2[i],s2[s2.size()-i-1]);
		for (int i=0;i<s1.size();i++)
		{
			f[i]=0;if (f[i-1]==0&&(i&1))continue;
			if (s1[i]==s2[f[i-1]])f[i]=f[i-1]+1;
			f[i]=max(f[i],f[i-2]);if (f[i]==s2.size())ff=1;
		}
		if (ff)YES
		else NO
	}
	return 0;
}