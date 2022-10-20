#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	bool t;
	int i,j;
	string ans="";
	getline(cin,s);
	for(i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{
			if(i==0)
			{
				ans+="...";
			}
			else if(ans[ans.size()-1]==' ')
			{
				ans+="...";
			}
			else
			{
				ans+=" ...";
			}
			i+=2;
		}
		else if(s[i]==',')
		{
			if(i==s.size()-1)
			{
				ans+=",";
			}
			else
			{
				ans+=", ";
			}
		}
		else if(isdigit(s[i]))
		{
			t=true;
			for(j=i;isdigit(s[j]);j++)
			{
				ans+=s[j];
			}
			for(;s[j]==' ';j++);
			if(isdigit(s[j]))
			{
				ans+=" ";
			}
			i=j-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}