#include<bits/stdc++.h>
using namespace std;

const int M=2e5+10;
struct node
{
	int a,b;
}ans[M];int cnt;

int T;

int main()
{
	cin>>T;
	while(T--)
	{
		int n;cin>>n;cnt=0;
		if (n<=8)
		{
			for (int j=n-1;j>2;j--)
				ans[++cnt].a=j,ans[cnt].b=n;
			for (int k=n;k!=1;k=(k+1)/2)
				ans[++cnt].a=n,ans[cnt].b=2;
		}
		else
		{
			for (int j=n-1;j>2;j--)
				if (j!=8)
					ans[++cnt].a=j,ans[cnt].b=n;
			for (int k=n;k!=1;k=(k%8==0?k/8:k/8+1))
				ans[++cnt].a=n,ans[cnt].b=8;
			ans[++cnt].a=8,ans[cnt].b=2;
			ans[++cnt].a=8,ans[cnt].b=2;
			ans[++cnt].a=8,ans[cnt].b=2;
		}
		cout<<cnt<<endl;
		for (int i=1;i<=cnt;i++)
			cout<<ans[i].a<<' '<<ans[i].b<<endl;
	}
}