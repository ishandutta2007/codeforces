#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int i;
	char b1,b2;
	cin>>s;
	for(i=0;i<5;i++)
	{
		cin>>b1>>b2;
		if(b1==s[0]||b2==s[1])
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}