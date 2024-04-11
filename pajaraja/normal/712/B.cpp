#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	string s;
	cin>>s;
	int l=0,r=0,u=0,d=0,miin=100000000,n=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='L') l++;
		if(s[i]=='D') d++;
		if(s[i]=='R') r++;
		if(s[i]=='U') u++;
	}
	if(s.size()%2!=0) printf("-1");
	else
	{
		for(int i=0;i<=s.size();i+=2)
		{
			int so=max(d-i/2,0)+max(u-i/2,0)+max(l-(n-i)/2,0)+max(r-(n-i)/2,0);
			miin=min(so,miin);
		}
		printf("%d",miin);
	}
	return 0;
}