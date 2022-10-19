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
	ll t,n,m,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(i==n-1&&j==m-1)
				{
					cout<<"W";
				}
				else
				{
					cout<<"B";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}