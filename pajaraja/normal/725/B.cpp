#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	int t;
	unsigned long long  st=1,n=0;
	string s;
	cin>>s;
	t=s[s.size()-1]-'a'+1;
	for(int i=s.size()-2;i>=0;i--)
	{
		n+=st*(s[i]-'0');
		st*=10;
	}
	unsigned long long r;
	int l=n%4;
	if(l==1||l==3) r=((n/4)*4)*4;
	else r=(((n-1)/4)*4)*4+7;
	if(t==6) cout<<r+1;
	if(t==5) cout<<r+2;
	if(t==4) cout<<r+3;
	if(t==3) cout<<r+6;
	if(t==2) cout<<r+5;
	if(t==1) cout<<r+4;
	return 0;
}