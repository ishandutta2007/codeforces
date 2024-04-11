#include <bits/stdc++.h>
using namespace std;
string s,ans;
int t;
int main(){
	char c;
	int i,j;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ans="";
		for(i=0;i<s.size();i=j)
		{
			c=s[i];
			for(j=i+1;s[j]==s[i];j++);
			if((j-i)%2==1&&ans.find(c)==-1)
			{
				ans+=c;
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	return 0;
}