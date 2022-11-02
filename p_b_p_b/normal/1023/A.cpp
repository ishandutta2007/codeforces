#include<bits/stdc++.h>
using namespace std;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(long long& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1;
        }
        return x=(f?-x:x),*this;
    }
}read;
#define sz 201010
string s,t;
int main()
{
	int n,m,i,j,k,x,y,z;
	read>>n>>m;
	cin>>s>>t;
	if (n>m+1) return 0&puts("NO");
	for (i=0;i<n;i++) if (s[i]=='*') break;
	x=i;
	if (x==n) return 0&puts(s==t?"YES":"NO");
	for (i=0;i<x;i++) if (s[i]!=t[i]) return 0&puts("NO");
	for (i=n-1;i>x;i--) if (s[i]!=t[m-(n-i)]) return 0&puts("NO");
	puts("YES");
}