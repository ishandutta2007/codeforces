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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n;
char s[M];

signed main()
{
	WT
	{
		cin>>n>>s+1;
		if (s[1]==s[2])
		{
			cout<<s[1]<<s[1];puts("");
			continue;
		}
		int now=1;
		for (int i=2;i<=n;i++)
		{
			if (s[i]<=s[i-1])now=i;
			else break;
		}
		for (int i=1;i<=now;i++)cout<<s[i];
		for (int i=now;i>=1;i--)cout<<s[i];
		puts("");
	}
	return 0;
}