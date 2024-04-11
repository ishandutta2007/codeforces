#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=107;

ll n,k,m,t[N];

ll sum,ans;

int main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=k;i++)
		cin>>t[i],sum+=t[i];
	sort(t+1,t+k+1);
	for(ll i=0;i<=n;i++)
	{
		ll tot=0;
		ll rem;
		if(m>=sum*i)
			rem=m-sum*i;
		else
			break;
		tot+=(k+1)*i;
		for(int j=1;j<=k;j++)
			for(int h=1;h<=n-i;h++)
				if(rem>=t[j])
					rem-=t[j],tot++;
		ans=max(ans,tot);
	}
	cout<<ans;
}