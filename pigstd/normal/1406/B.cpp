#include<bits/stdc++.h>
#define int long long
#define MINN -244000000000000000
using namespace std;

const int M=2e5+10;
int T,n,a[M],a1[M],a2[M];

bool cmp(int a,int b)
{
	return abs(a)>abs(b);
}

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;int ans=MINN,sumz=0,sumf=0,ze=0;
		if (n==5)
		{
			int aa=1;
			for (int i=1;i<=5;i++)cin>>a[i],aa*=a[i];
			cout<<aa<<endl;continue;
		}
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
			if (a[i]>0)a1[++sumz]=a[i];
			if (a[i]<0)a2[++sumf]=a[i];
			if (a[i]==0)ze++;
		}
		sort(a1+1,a1+1+sumz,cmp);
		sort(a2+1,a2+1+sumf,cmp);
		if (ze)ans=0;
		if (sumz==0&&sumf>=5)
		{
			int aa=1;
			for (int i=n;i>n-5;i--)
				aa*=a2[i];
			ans=max(ans,aa);
		}
		else
		{
			for (int i=1;i<=5&&i<=sumz;i+=2)
			{
				if ((5-i)>sumf)continue;
				int aa=1;
				for (int j=1;j<=i;j++)aa*=a1[j];
				for (int j=1;j<=5-i;j++)aa*=a2[j];
				ans=max(ans,aa);
			}
		}
		cout<<ans<<endl;
		for (int i=1;i<=sumz;i++)a1[i]=0;
		for (int i=1;i<=sumf;i++)a2[i]=0;
	}
	return 0;
}

/*
3
6
-1 -2 -3 1 2 -1
6
-1 0 0 0 -1 -1
6
-9 -7 -5 -3 -2 1
*/