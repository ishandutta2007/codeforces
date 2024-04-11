#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,x,a[N],v[N],r,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>x)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i],v[i]=0;
		sort(a+1,a+n+1),r=1,A=n;
		for(int i=1;i<=n;i++)
			if(!v[i])
			{
				while(r<n&&a[i]*x>a[r])
					r++;
				if(r<=n&&a[i]*x==a[r])
					v[r++]=1,A-=2;
			}
		cout<<A<<'\n';
	}
}