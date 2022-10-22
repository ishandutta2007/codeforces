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

const int M=5e5+10;
int n,m,ans=1;
string s;

signed main()
{
	n=read(),m=read();cin>>s;
	for (int i=2;i<=n;i++)
	{
		if (s[i-1]<s[(i-1)%ans])ans=i;
		else if (s[i-1]>s[(i-1)%ans]) break;
	}
	for (int i=1;i<=m;i++)
		cout<<s[(i-1)%ans];
	return 0;
}