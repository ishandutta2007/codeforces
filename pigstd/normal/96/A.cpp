#include<bits/stdc++.h>
using namespace std;

string a;

int main()
{
	cin>>a;
	for (int i=6;i<a.size();i++)
	{
		bool flag=0;
		char ch=a[i];
		for (int j=i-6;j<=i;j++)
			if (a[j]!=ch)
				{flag=1;break;}
		if (!flag)
			{cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}