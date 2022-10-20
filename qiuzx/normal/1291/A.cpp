#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	int t,n,i,j;
	vector<int> od;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		od.clear();
		for(i=0;i<s.size();i++)
		{
			if((s[i]-'0')%2==1)
			{
				od.push_back(i);
			}
		}
		if(od.size()==0)
		{
			cout<<-1<<endl;
			continue;
		} 
		if(od.size()%2==1)
		{
			if(od.size()==1)
			{
				cout<<-1<<endl;
				continue;
			}
			else
			{
				od.erase(od.begin());
			}
		}
		for(i=0;i<od.size();i++)
		{
			cout<<s[od[i]];
		}
		cout<<endl;
	}
	return 0;
}