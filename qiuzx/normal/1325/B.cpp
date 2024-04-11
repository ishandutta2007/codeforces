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
int t,n;
vector<int> v;
int main(){
	int i,x,ans;
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		ans=1;
		for(i=1;i<v.size();i++)
		{
			if(v[i]!=v[i-1])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}