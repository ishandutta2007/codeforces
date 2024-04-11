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
int n,a[M],ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i+=2)
		ans+=a[i+1]-a[i];
	cout<<ans<<endl;
	return 0;
}