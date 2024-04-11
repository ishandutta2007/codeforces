#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	int n;
	string s,r;
	cin>>n;
	cin>>s;
	r=s;
	int p1=0,p2=n-1,cnt=n-1;
	while(cnt>=0)
	{
		r[p2]=s[cnt];
		cnt--;
		if(cnt==-1) break;
		r[p1]=s[cnt];
		cnt--;
		p1++;
		p2--;
	}
	cout<<r;
	return 0;
}