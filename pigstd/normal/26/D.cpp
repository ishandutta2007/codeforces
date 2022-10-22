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

int n,m,k;

signed main()
{
	n=read(),m=read(),k=read();
	if (n-m+k<0)return puts("0"),0;
	if (k>=m)return puts("1"),0;
	double ans=1;k++;
	for (int i=1;i<=k;i++)
		ans=ans*(m-i+1)/(n+i);
	ans=1-ans;printf("%.8lf",ans);
	return 0;
}
/*

*/