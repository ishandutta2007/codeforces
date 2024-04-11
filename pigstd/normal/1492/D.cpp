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

const int M=2e5+10;
int a,b,k;
int ans1[M],ans2[M];

signed main()
{
	a=read(),b=read(),k=read();
	if (a==0)
	{
		if (k)return puts("No"),0;puts("Yes");
		for (int i=1;i<=b;i++)cout<<1;puts("");
		for (int i=1;i<=b;i++)cout<<1;puts("");
		return 0;
	}
	if (b==1)
	{
		if (k)return puts("No"),0;puts("Yes");
		cout<<1;for (int i=1;i<=a;i++)cout<<0;puts("");
		cout<<1;for (int i=1;i<=a;i++)cout<<0;puts("");
		return 0;
	}
	ans1[1]=ans2[1]=1;int len=a+b;
	if (k>=a+b-1)return puts("No"),0;
	puts("Yes")
	;ans1[2]=ans2[2+k]=1;a-=k,b--;
	for (int i=1;a<0;i++,a++,b--)
		ans2[i+2]=ans1[i+2]=1;
	for (int i=k+3;i<=k+b+1;i++)
		ans1[i]=ans2[i]=1;
	for (int i=1;i<=len;i++)
		cout<<ans1[i];puts("");
	for (int i=1;i<=len;i++)
		cout<<ans2[i];puts("");
	return 0;
}
/*

*/