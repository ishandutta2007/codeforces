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
ll n,g[N],k;
bool book[N];
vector<ll> lft;
int main(){
	ll t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<=n;i++)
		{
			book[i]=false;
		}
		lft.clear();
		for(i=0;i<n;i++)
		{
			cin>>k;
			for(j=0;j<k;j++)
			{
				cin>>g[j];
			}
			for(j=0;j<k;j++)
			{
				if(!book[g[j]])
				{
					book[g[j]]=true;
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				lft.push_back(i);
			}
		}
		if(lft.size())
		{
			cout<<"IMPROVE"<<endl;
			cout<<lft[0]+1<<" ";
			for(i=1;i<=n;i++)
			{
				if(!book[i])
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else
		{
			cout<<"OPTIMAL"<<endl;
		}
	}
	return 0;
}