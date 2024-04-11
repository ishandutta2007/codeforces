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

const int M=105;
int a[M];

signed main()
{
	int n=read(),k=0,sum1=0,sum2=0;
	for (int i=1;i<=n;i++)
		a[i]=read(),k=max(k,a[i]),sum1+=a[i];
	for (int i=1;i<=n;i++)
		sum2+=k-a[i];
	if (sum2>sum1){cout<<k<<endl;return 0;} 
	int pp=sum1-sum2;
	k+=pp/n+1;cout<<k<<endl;
	return 0;
}