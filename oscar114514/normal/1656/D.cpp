#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	long long n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if((n&-n)==n)cout<<-1<<"\n";
		else
		{
			long long d=1;
			while(n%2==0)
			{
				n/=2;
				d*=2;
			}
			d*=2;
			if(n<d)cout<<n<<"\n";
			else cout<<d<<"\n";
		}
	}
	
	return 0;
}