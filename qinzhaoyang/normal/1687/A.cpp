#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int n,k,a[N],s[N],A;
main()
{
	for(cin>>n;cin>>n>>k;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],s[i]=s[i-1]+a[i];
		if(n==1)
		{
			cout<<s[1]+k-1<<'\n';
			continue;
		}
		if(k>=n)
			cout<<s[n]+(k-1)*n-n*(n-1)/2<<'\n';
		else
		{
			A=0;
			for(int i=k;i<=n;i++)
				A=max(A,s[i]-s[i-k]);
			cout<<A+k*(k-1)/2<<'\n';
		}
	}
}