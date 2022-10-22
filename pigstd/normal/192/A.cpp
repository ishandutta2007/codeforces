#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin>>n;
//	if (n==1)cout<<"Yes";
	for (int i=1;i<=sqrt(2*n);i++)
	{
		bool flag=0;
		int tl=1,tr=sqrt(2*n),k=i*(i+1);
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (Mid*(Mid+1)+k==2*n)
				{flag=1;break;}
			else if (Mid*(Mid+1)+k<2*n)
				tl=Mid+1;
			else
				tr=Mid-1;
		}
		if (flag)
			{cout<<"Yes";return 0;}
	}
	cout<<"No";
	return 0;
}