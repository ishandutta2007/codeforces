#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b,c,d;

int main()
{
	cin>>a>>b>>c>>d;
	for(int i=1;i<=(1e7);i++)
	{
		if(i>=b&&i>=d)
		if((i-b)%a==0&&(i-d)%c==0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1;
}