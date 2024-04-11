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
	int t,n,i,x,y;
	vector<int> a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a.clear();
		b.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
			b.push_back(x);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}