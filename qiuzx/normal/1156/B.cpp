#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,i,j;
	string odd="",even="",s,ns;
	vector<string> ans;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>s;
		sort(s.begin(),s.end());
		odd="";
		even="";
		for(j=0;j<s.size();j++)
		{
			if((s[j]-'a'+1)%2==0)
				even+=s[j];
			else
				odd+=s[j];
		}
		if(odd=="")
			ns=even;
		else if(even=="")
			ns=odd;
		else if(abs(odd[odd.size()-1]-even[0])!=1)	
			ns=odd+even;
		else if(abs(even[even.size()-1]-odd[0])!=1)
			ns=even+odd;
		else
			ns="No answer";
		ans.push_back(ns);
	}
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}