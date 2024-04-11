#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int d,m,a;
	cin>>s>>a;
	d=((s[0]-'0')*10+(s[1]-'0'));
	m=((s[3]-'0')*10+(s[4]-'0'));
	m+=a;
	d+=m/60;
	m%=60;
	d%=24;
	if(d/10<1)
	{
		cout<<0;
	}
	cout<<d<<":";
	if(m/10<1)
	{
		cout<<0;
	}
	cout<<m<<endl;
	return 0;
}