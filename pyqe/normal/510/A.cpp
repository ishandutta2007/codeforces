#include <iostream>

using namespace std;

int main()
{
	long long r,c,i,j;
	
	cin>>r>>c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i%2==0)
			{
				cout<<"#";
			}
			else if(i%4==1)
			{
				if(j==c-1)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
			else
			{
				if(j==0)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
		}
		cout<<endl;
	}
}