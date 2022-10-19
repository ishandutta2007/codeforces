#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
		}
		else
		{
			if((n-1)%9==0)
			{
				for(i=0;i+2<n;i++)
				{
					cout<<2;
				}
				cout<<49<<endl;
			}
			else
			{
				for(i=0;i<n-1;i++)
				{
					cout<<2;
				}
				cout<<9<<endl;
			}
		}
	}
	return 0;
}