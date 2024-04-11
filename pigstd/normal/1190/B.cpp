#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define YES puts("cslnb");
#define NO puts("sjfnb");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n,a[M],ans,cnt,cnt2;
map<int,int>t,f;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)t[a[i]=read()]++,f[a[i]]=1;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		if (t[a[i]]>=3||(t[a[i]]==2&&t[a[i]-1]>=1)){YES return 0;}
		if (t[a[i]]>=2&&f[a[i]]!=0)cnt++,f[a[i]]=0;
		if (a[i]==0)cnt2++;
	}
	if (cnt>=2){YES return 0;}
	if (cnt2>=2){YES return 0;}
	for (int i=1;i<=n;i++)
		if (a[i]!=0)
			ans+=a[i]-i+1;
	if (ans&1)NO
	else YES 
	return 0;
}