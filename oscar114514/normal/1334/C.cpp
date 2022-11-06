#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long a[333333],b[333333],s[333333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long ans=0,minn=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			if(i>1)
			{
				ans+=max(a[i]-b[i-1],0ll);
				minn=min(minn,min(a[i],b[i-1]));
			}
//			cerr<<i<<' '<<ans<<' '<<minn<<endl;
		}
		ans+=max(a[1]-b[n],0ll);
		minn=min(minn,min(a[1],b[n]));
		cout<<ans+minn<<endl;
	}
	return 0;
}