#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int b[1000000];
int main(int argc, char** argv)
{
	fill(b,b+1000000,0);
	int q;
	cin>>q;
	while(q--)
	{
		long long a;
		char t;
		cin>>t>>a;
			long long z=1,y=1,k;
			int bt=0;
			for(int i=0;i<18;i++)
			{
				k=(a/z)%10;
				bt+=(k%2)*y;
				y*=2;
				z*=10;
			}
			if(t=='+') b[bt]++;
			if(t=='-') b[bt]--;
			if(t=='?') cout<<b[bt]<<endl;
	}
	return 0;
}