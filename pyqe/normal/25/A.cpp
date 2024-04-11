#include <iostream>

using namespace std;

int main()
{
	long long n,i,p=-1;
	bool g;
	
	cin>>n;
	long long a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>1)
		{
			if(p==-1)
			{
				if(g&&a[i]%2==0||!g&&a[i]%2==1)
				{
					p=i;
					break;
				}
			}
			else
			{
				if(a[i]%2==0)
				{
					break;
				}
				else
				{
					p=(p+1)%2;
					break;
				}
			}
		}
		else if(i==1)
		{
			if(a[0]%2==0)
			{
				if(a[1]%2==0)
				{
					g=false;
				}
				else
				{
					p=1;
				}
			}
			else
			{
				if(a[1]%2==0)
				{
					p=0;
				}
				else
				{
					g=true;
				}
			}
		}
	}
	cout<<p+1<<endl;
}