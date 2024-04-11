#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

int T;
int n;

ll a[N],b[N],ans;

int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]),ans+=(i%2==0)*a[i];
		for(int i=0;i<n;i++)
			b[i]=0;
		for(int i=0;i<n;i+=2)
			if(i+1<n)
				b[i]=a[i+1]-a[i];
		ll s=0,mx=0;
		for(int i=0;i<n;i++)	
			s=max(b[i],s+b[i]),mx=max(mx,s);
		s=0;
		for(int i=0;i<n;i++)
			b[i]=0;
		for(int i=1;i<n;i+=2)
			if(i+1<n)
				b[i]=a[i]-a[i+1];
		for(int i=0;i<n;i++)	
			s=max(b[i],s+b[i]),mx=max(mx,s);
		printf("%lld\n",ans+mx);
	}	
}