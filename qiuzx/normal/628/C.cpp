#include <bits/stdc++.h>
#define N 100010
using namespace std;
int main(){
	string s,ans="";
	char tem,c[N];
	int n,cur,i;
	scanf("%d%d%s",&n,&cur,c);
	s=c;
	for(i=0;i<n;i++)
	{
		if(!cur)
		{
			cout<<ans<<s<<endl;
			return 0;
		}
		if(s[0]-'a'>'z'-s[0])
		{
			if(cur<s[0]-'a')
			{
				ans+=s[0]-cur;
				cur=0;
			}
			else
			{
				ans+="a";
				cur-=s[0]-'a';
			}
		}
		else
		{
			if(cur<'z'-s[0])
			{
				ans+=s[0]+cur;
				cur=0;
			}
			else
			{
				ans+="z";
				cur-='z'-s[0];
			}
		}
		s=s.substr(1);
	}
	if(cur)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<ans<<s<<endl;
	}
	return 0;
}