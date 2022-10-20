#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,ans=0;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		for(j=i;j<s.size();j++)
		{
			if(s.find(s.substr(i,j-i+1),i+1)<s.size())
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}