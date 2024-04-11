#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e6+1e3+7;

ll n,k;

ll a[N],d[N][20],ans;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],d[i][0]=a[i]%k;
	for(int j=1;j<=17;j++)
		for(int i=1;i<=n;i++)
			d[i][j]=(d[i][j-1]*d[i+(1<<(j-1))][j-1])%k;
	for(int i=1;i<=n;i++)
	{
		ll now=i,g=1;
		for(int j=17;j>=0;j--)
			if(g*d[now][j]%k!=0)
				g=(g*d[now][j])%k,now+=(1<<j);
		ans+=n-now+1;
	}
	cout<<ans;
}