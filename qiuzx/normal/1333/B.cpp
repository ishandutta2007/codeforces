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
#define N 100010
using namespace std;
ll n,a[N],b[N];
bool neg,pos;
int main(){
	ll t,i;
	cin>>t;
	while(t--)
	{
		pos=neg=false;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>b[i])
			{
				if(!neg)
				{
					i=-1;
					break;
				}
			}
			else if(a[i]<b[i])
			{
				if(!pos)
				{
					i=-1;
					break;
				}
			}
			if(a[i]>0)
			{
				pos=true;
			}
			else if(a[i]<0)
			{
				neg=true;
			}
		}
		if(i==-1)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}