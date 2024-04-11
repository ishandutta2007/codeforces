#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	int n,t;
	bool u,d,l,r;
	u=l=d=r=true;
	string s;
	cin>>n;
	cin>>s;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=s[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		t=a[i];
		if(t==3||t==6||t==9||t==0) r=false;
		if(t==1||t==4||t==7||t==0) l=false;
		if(t==7||t==0||t==9) d=false;
		if(t==1||t==2||t==3) u=false;
	}
	if(u||r||l||d) cout<<"NO";
	else cout<<"YES";
	return 0;
}