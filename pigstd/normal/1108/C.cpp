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

const int M=1e6;
int n;string s;
int a[M],ans=1e18,b[M];

//RGB

signed main()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++)
		if (s[i-1]=='R')a[i]=1;
		else if (s[i-1]=='G')a[i]=2;
		else a[i]=3;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			for (int k=1;k<=3;k++)
			{
				if (i==j||i==k||j==k)continue;
				int sum=0;
				for (int p=1;p<=n;p++)
				{
					if (p%3==0)sum+=a[p]==i?0:1;
					if (p%3==1)sum+=a[p]==j?0:1;
					if (p%3==2)sum+=a[p]==k?0:1;
				}
				if (sum<ans)
				{
					ans=sum;
					for (int p=1;p<=n;p++)
					{
						if (p%3==0)b[p]=i;
						if (p%3==1)b[p]=j;
						if (p%3==2)b[p]=k;
					}
				}
			}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
		if (b[i]==1)cout<<'R';
		else if (b[i]==2)cout<<"G";
		else cout<<'B';
	return 0;
}