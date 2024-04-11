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

const int M=1010;
string s;int a[M],n;

signed main()
{
	cin>>s;n=s.size();
	for (int i=1;i<=n;i++)
		a[i]=s[i-1]-'a'+1;
	for (int i=1;i<=n;i++)
		if (a[i]==1&&a[i+1]!=1)cout<<"1 ";
		else if (a[i]==2&&a[i+1]==1)cout<<"1 ";
		else cout<<"0 ";
	return 0;
}