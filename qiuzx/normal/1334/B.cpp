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
ll t,n,mx;
vector<ll> a;
int main(){
	ll i,x,sum;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>mx;
		a.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		for(i=0;i<a.size();i++)
		{
			if(sum+a[i]<mx*(i+1))
			{
				break;
			}
			sum+=a[i];
		}
		cout<<i<<endl;
	}
	return 0;
}