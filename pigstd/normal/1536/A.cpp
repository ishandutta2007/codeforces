#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=1e5+10;
int n,a[M],b[M];

signed main()
{
	WT
	{
		n=read();int f=0;
		for (int i=1;i<=n;i++)a[i]=read(),f|=(a[i]<0);
		if (f){NO continue;}
		YES
		cout<<101<<endl;
		for (int i=0;i<=100;i++)cout<<i<<' ';puts("");
	}
	return 0;
}