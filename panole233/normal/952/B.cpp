#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string s;
int cnt;

int main()
{
	cnt=0;
	for (int i=0; i<10; i++)
	{
		cout<<i<<endl;
		getline(cin,s);
		if (s!="no")
		{
			if (s=="cool"||s=="not bad"||s=="don't touch me"||s=="don't think so"||s=="great") printf("normal\n"); 
			else printf("grumpy\n");
			return 0;
		}
		else cnt++;
		if (cnt==5)
		{
			printf("normal\n"); 
			return 0;
		}
	}
	return 0;
}