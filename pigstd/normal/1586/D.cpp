#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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
int n,p[M],t,x[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		cout<<"? ";
		for (int j=1;j<=n;j++)
			if (i==j)cout<<"2 ";
			else cout<<"1 ";
		cout<<endl;cin>>x[i];
		if (x[i]==0)t=i;
	}p[t]=n;
	for (int i=n-1;i>=1;i--)
	{
		int tmp=-1;
		for (int j=1;j<=n;j++)
			if (x[j]==t&&x[j]!=j)tmp=j;
		if (tmp!=-1)
			t=tmp,p[t]=i;
		else
		{
			cout<<"? ";
			for (int j=1;j<=n;j++)
				if (j==t)cout<<"1 ";
				else cout<<"2 ";
			cout<<endl;cin>>t;
			p[t]=i;
		}
	}
	cout<<"!";
	for (int i=1;i<=n;i++)
		cout<<' '<<p[i];
	cout<<endl;
	return 0;
}