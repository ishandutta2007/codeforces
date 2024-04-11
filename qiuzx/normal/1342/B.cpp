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
ll t;
string s;
int main(){
	ll i;
	string ss;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ss=s;
		sort(ss.begin(),ss.end());
		if(ss[0]==ss[ss.size()-1])
		{
			cout<<s;
		}
		else
		{
			for(i=0;i<s.size()*2;i++)
			{
				if(i%2==0)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}