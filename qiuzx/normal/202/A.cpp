#include <bits/stdc++.h>
using namespace std;
int main(){
	string c;
	char s[100];
	int i;
	cin>>c;
	for(i=0;i<c.size();i++)
	{
		s[i]=c[i];
	}
	sort(s,s+c.size());
	reverse(s,s+c.size());
	cout<<s[0];
	for(i=1;i<c.size();i++)
	{
		if(s[i]!=s[i-1])
		{
			break;
		}
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}