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

const int M=105*105;
int n;
struct node
{
	int x,y;
}a1[M],a2[M];int cnt1,cnt2,l1,l2;

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((i+j)&1)
				a2[++cnt2].x=i,a2[cnt2].y=j;
			else
			 	a1[++cnt1].x=i,a1[cnt1].y=j;
	int m=n*n;while(m--)
	{
		int x;cin>>x;
		if (x==1)
		{
			if (l1!=cnt1)
			{
				l1++;
				cout<<2<<' '<<a1[l1].x<<' '<<a1[l1].y<<endl;
				continue;
			}
			else
			{
				l2++;
				cout<<3<<' '<<a2[l2].x<<' '<<a2[l2].y<<endl;
				continue;
			}
		}
		if (x==2)
		{
			if (l2!=cnt2)
			{
				l2++;
				cout<<1<<' '<<a2[l2].x<<' '<<a2[l2].y<<endl;
				continue;
			}
			else
			{
				l1++;
				cout<<3<<' '<<a1[l1].x<<' '<<a1[l1].y<<endl;
				continue;
			}
		}
		if (x==3)
		{
			if (l1!=cnt1)
			{
				l1++;
				cout<<2<<' '<<a1[l1].x<<' '<<a1[l1].y<<endl;
				continue;
			}
			else
			{
				l2++;
				cout<<1<<' '<<a2[l2].x<<' '<<a2[l2].y<<endl;
				continue;
			}
		}
	}
	return 0;
}