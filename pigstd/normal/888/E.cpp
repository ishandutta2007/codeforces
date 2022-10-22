#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=(1<<18)+10;
int n,m,a[40],sum1[M],sum2[M],b[40],ans;

int getsum1(int kk)
{
	int len=0,sum=0;
	while(kk)
	{
		len++;
		if (kk&1)sum+=a[len];
		sum%=m;
		kk>>=1;
	}
	return sum;
}

int getsum2(int kk)
{
	int len=0,sum=0;
	while(kk)
	{
		len++;
		if (kk&1)
			sum+=b[len];
		sum%=m;
		kk>>=1;
	}
	return sum;
}

signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i],a[i]%=m;
	for (int i=1;i<=n-n/2;i++)
		b[i]=a[i+n/2];
	for (int i=n/2+1;i<=n;i++)a[i]=0;
	int k=n-n/2;n/=2;
	for (int i=0;i<(1<<n);i++)
		sum1[i]=getsum1(i);
	for (int i=0;i<(1<<k);i++)
		sum2[i]=getsum2(i);
	sort(sum1+1,sum1+(1<<n));sort(sum2+1,sum2+(1<<k));
	for (int i=0;i<(1<<n);i++)
	{
		int tl=0,tr=(1<<k)-1,p=-1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (sum1[i]+sum2[Mid]>=m)
				tr=Mid-1;
			else tl=Mid+1,p=Mid;
		}
		if (p==-1)ans=max(ans,sum1[i]+sum2[(1<<k)-1]);
		else ans=max(ans,sum1[i]+sum2[p]);
	}
	cout<<ans;
	return 0;
}