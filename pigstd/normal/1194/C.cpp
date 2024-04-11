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

string s,t,p;
int t1[30],t2[30];

signed main()
{
	WT
	{
		cin>>s>>t>>p;int f=1;
		for (int i=1;i<=26;i++)t1[i]=t2[i]=0;
		int l=0,r=0;
		for (int l=0;l<s.size();l++)
		{
			while(r<t.size()&&t[r]!=s[l])r++;
			if (r>=t.size())f=0;r++;
		}
		for (int i=0;i<s.size();i++)
			t1[s[i]-'a'+1]++;
		for (int i=0;i<t.size();i++)
			t2[t[i]-'a'+1]++;
		for (int i=0;i<p.size();i++)
			t1[p[i]-'a'+1]++;
		for (int i=1;i<=30;i++)
			if (t2[i]>t1[i])f=0;
		if (f)YES
		else NO
	}
	return 0;
}
/*

*/