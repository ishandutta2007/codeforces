#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int i,num=0,k,n;
	cin>>n>>k>>s;
	for(i=1;i<s.size();i++)
	{
		if(s[i]=='#'&&s[i-1]=='.')
		{
			num=1;
		}
		else if(s[i]=='#')
		{
			num++;
		}
		if(num>=k)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}