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

string p=" abcdefghijklmnopqrstuvwxyz";

signed main()
{
	int n=read(),k=read();string s="a";
	for (int i=2;i<=k;i++)
	{
		s+=p[i];
		for (int j=i-1;j>=1;j--)
			s+=p[i],s+=p[j];
	}
	cout<<'a';
	for (int i=0;i<n-1;i++)
		cout<<s[i%(s.size())];
	return 0;
}
//