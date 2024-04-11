#include<bits/stdc++.h>
using namespace std;

string a;
bool flag;
int last=-1;

int main()
{
	cin>>a;
	for (int i=0;i<a.size();i++)
	{
		if (a[i]=='@')
			last=i;
		if (a[i]=='@'&&(a[i+1]=='@'||a[i+2]=='@'))
			{flag=1;break;}
	}
	if (flag||a[0]=='@'||last==-1||a[a.size()-1]=='@')
		{cout<<"No solution";return 0;}
	for (int i=0;i<a.size();i++)
	{
		cout<<a[i];
		if (a[i]=='@')
		{
			cout<<a[++i];
			if (i!=last+1)
				cout<<",";
		}
	}
	return 0;
}