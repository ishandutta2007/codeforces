#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
bool p[3];
int main()
{
 	string s;
 	cin>>s;
 	if(s.size()<5){puts("Too weak");return 0;}
 	for(int i=0;i<s.size();i++)
 	{
	 		if(s[i]>='a'&&s[i]<='z')p[0]=true;
	 		if(s[i]>='A'&&s[i]<='Z')p[1]=true;
	 		if(s[i]>='0'&&s[i]<='9')p[2]=true;
	}
	if(p[0]&&p[1]&&p[2])
	puts("Correct");else puts("Too weak");
	return 0;
}