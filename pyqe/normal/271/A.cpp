#include <iostream>

using namespace std;

int main()
{
	long long n,i,m;
	bool a[10];
	
	cin>>n;
	while(1)
	{
		n++;
		for(i=0;i<10;i++)
		{
			a[i]=false;
		}
		m=n;
		while(m>0)
		{
			if(a[m%10]==false)
			{
				a[m%10]=true;
			}
			else
			{
				i=-1;
				break;
			}
			m/=10;
		}
		if(i==-1)
		{
			continue;
		}
		cout<<n<<endl;
		return 0;
	}
}