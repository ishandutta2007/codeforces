//AFO countdown:8 Days
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

const int M=50;
int n,a[M],b[M];
string s;

signed main()
{
	WT
	{
		n=read();cin>>s;
		for (int i=1;i<=n;i++)
			a[i]=b[i]=s[i-1]-'a';
		sort(b+1,b+1+n);
		int res=0;
		for (int i=1;i<=n;i++)
			res+=a[i]!=b[i];
		cout<<res<<endl; 
	}
	return 0;
}