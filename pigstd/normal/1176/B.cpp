#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int T,n,f[20];
vector<int>e[4];

signed main()
{
	T=read();
	while(T--)
	{
		int n=read(),cnt1=0,cnt2=0,cnt3=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			if (x%3==0)cnt3++;
			else if (x%3==1)cnt1++;
			else cnt2++;
		}
		int ans=cnt3,t=min(cnt1,cnt2);
		ans+=t;cnt1-=t,cnt2-=t;
		if (cnt1!=0)ans+=cnt1/3;
		else ans+=cnt2/3;
		cout<<ans<<endl;
	}
	return 0;
}