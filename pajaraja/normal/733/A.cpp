#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) 
{
	string s;
	cin>>s;
	int n=s.size(),prev=-1,max=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A'||s[i]=='E'||s[i]=='O'||s[i]=='I'||s[i]=='U'||s[i]=='Y')
		{
			max=i-prev>max?i-prev:max;
			prev=i;
		}
	}
	max=n-prev>max?n-prev:max;
	cout<<max;
	return 0;
}