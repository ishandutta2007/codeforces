#include <bits/stdc++.h>
#define N 300010
using namespace std;
int t;
string s,ans;
vector<char> odd,even;
bool book[N];
int main(){
	int i,j;
	cin>>t;
	while(t--)
	{
		cin>>s;
		odd.clear();
		even.clear();
		for(i=0;i<s.size();i++)
		{
			if((s[i]-'0')%2==0)
			{
				even.push_back(s[i]);
			}
			else
			{
				odd.push_back(s[i]);
			}
		}
		for(i=0,j=0;i<odd.size()||j<even.size();)
		{
			if(i==odd.size())
			{
				cout<<even[j];
				j++;
			}
			else if(j==even.size())
			{
				cout<<odd[i];
				i++;
			}
			else if(odd[i]<even[j])
			{
				cout<<odd[i];
				i++;
			}
			else
			{
				cout<<even[j];
				j++;
			}
		}
		cout<<endl;
	}
	return 0;
}