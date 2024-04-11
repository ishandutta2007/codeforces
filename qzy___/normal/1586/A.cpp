#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int T,n,a[N],s,v;
signed main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		s=v=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i];
		for(int i=2;i<s;i++)
			if(s%i==0)
			{
				cout<<n<<'\n';
				for(int j=1;j<=n;j++)
					cout<<j<<' ';
				cout<<'\n';
				v=1;
				break;
			}
		if(!v)
			for(int i=1;i<=n;i++)
				if((s-a[i])%2==0)
				{
					cout<<n-1<<'\n';
					for(int j=1;j<=n;j++)
						if(j!=i)
							cout<<j<<' ';
					cout<<'\n';
					break;
				}
	}
}