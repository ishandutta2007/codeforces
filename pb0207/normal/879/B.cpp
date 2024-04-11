#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;

ll a[2001],k,n,mx;

ll cnt[601];

int main()
{
	cin>>n>>k;
	if(k>=n-1)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll tot=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==n)
		{
			cout<<n;
			return 0;
		}
		int j=i+1;
		while(1)
		{
			if(a[i]<a[j])
			{
				cnt[a[j]]++;
				if(cnt[a[j]]>=k)
				{
					cout<<a[j];
					return 0;
				}
				a[++tot]=a[i];
				break;
			}
			if(a[i]>a[j])
				j++,cnt[a[i]]++,a[++tot]=a[j];
			if(cnt[a[i]]>=k)
			{
				cout<<a[i];
				return 0;
			}
		}
		i=j-1;
	}
}