#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin>>str;
	int j=str.length()-3;
	int count=0,i;
	for(i=0;i<=j&&count<=2;i++)
	{
		if(str[i]=='D')
		{
			string str2=str.substr(i,5);
			if(!str2.compare("Danil"))
				count++;
		}
		else if(str[i]=='O')
		{
			string str2=str.substr(i,4);
			if(!str2.compare("Olya"))
				count++;
		}
		else if(str[i]=='S')
		{
			string str2=str.substr(i,5);
			if(!str2.compare("Slava"))
				count++;
		}
		else if(str[i]=='A')
		{
			string str2=str.substr(i,3);
			if(!str2.compare("Ann"))
				count++;
		}
		else if(str[i]=='N')
		{
			string str2=str.substr(i,6);
			if(!str2.compare("Nikita"))
				count++;
		}
	}
	if(count==1)
		cout<<"YES";
	else
		cout<<"NO";
}