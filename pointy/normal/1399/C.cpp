//20210613
#include<bits/stdc++.h>
using namespace std;
int T,n; 
int a[101],b[101],c[101];
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++) 
		{
			cin >> a[i];
			b[a[i]]++;
		}
		int ans=0,res=0;
		for (int s=1;s<=2*n;s++)
		{
			for (int i=1;i<=n;i++) c[i]=b[i];
			ans=0;
			for (int i=1;i<=n;i++)
			{
				if (s-a[i]>0&&c[s-a[i]]>0&&c[a[i]]>0)
				{
					c[a[i]]--;
					c[s-a[i]]--;
					if (c[a[i]]>=0&&c[s-a[i]]>=0) ans++;
					else c[a[i]]++,c[s-a[i]]++;
				}
			}
			res=max(res,ans);
		}
		cout << res << endl;
	}
	return 0;
}