#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=110;
int a[M],n,d,ans;

signed main()
{
	n=read(),d=read();for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++)
	{
		if (a[i]-a[i-1]==2*d)ans++;
		else if (a[i]-a[i-1]>2*d)ans+=2; 
	}ans+=2;
	cout<<ans<<endl;
	return 0;
}