#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
bool p[101];
void eratoster()
{
	int k;
	for(int i=2;i<100;i++)
	{
		if(p[i])
		{
			k=2*i;
			while(k<=100)
			{
				p[k]=false;
				k+=i;
			}
		}
	}
}
int main(int argc, char** argv) 
{
	string s;
	fill(p,p+101,true);
	eratoster();
	int bp;
	for(int i=2;i<50;i++)
	{
		if(p[i])
		{
			cout<<i<<endl;
			fflush(stdout);
			cin>>s;
			if(s[0]=='y') bp++;
		}
	}
	if(bp>=2)
	{
		cout<<"composite"<<endl;
		fflush(stdout);
		return 0;
	}
	if(bp==0 )
	{
		cout<<"prime"<<endl;
		fflush(stdout);
		return 0;
	}
	if(bp==1)
	{
		cout<<"4"<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y')
		{
			cout<<"composite"<<endl;
		    fflush(stdout);
		    return 0;
		}
		cout<<"9"<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y')
		{
			cout<<"composite"<<endl;
		    fflush(stdout);
		    return 0;
		}
		cout<<"25"<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y')
		{
			cout<<"composite"<<endl;
		    fflush(stdout);
		    return 0;
		}
		cout<<"49"<<endl;
		fflush(stdout);
		cin>>s;
		if(s[0]=='y')
		{
			cout<<"composite"<<endl;
		    fflush(stdout);
		    return 0;
		}
		cout<<"prime"<<endl;
		fflush(stdout);
		return 0;
	}
	return 0;
}