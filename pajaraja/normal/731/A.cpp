#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int main(int argc, char** argv) 
{
	int n,r=0;
	string s;
	cin>>s;
	r+=min(fabs(s[0]-'a'),26-fabs(s[0]-'a'));
	for(int i=1;i<s.size();i++)
	{
		r+=min(fabs(s[i]-s[i-1]),26-fabs(s[i]-s[i-1]));
	}
	printf("%d",r);
	return 0;
}