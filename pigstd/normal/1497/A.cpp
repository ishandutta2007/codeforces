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

const int M=110;
int n,a[M],t[M]; 

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=100;i++)t[i]=0;
		for (int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
		for (int i=0;i<=n;i++)
			if (!t[i])break;
			else cout<<i<<' ',t[i]--;
		for (int i=0;i<=100;i++)
			while(t[i])cout<<i<<' ',t[i]--;
		puts("");
	}
	return 0;
}