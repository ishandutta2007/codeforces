#include<bits/stdc++.h>
using namespace std;
int x[100010];
int main()
{
	int n,y=0;
	cin>>n;
	for(int i=1;;i++)
	{
		if(i*(i+1)/2>n)
			break;
		y++;
		x[y]=i*(i+1)/2;
	}
	int a=1,b=y;
	while(a<=b)
	{
		if(x[a]+x[b]==n)
		{
			cout<<"YES";
			return 0;
		}
		if(x[a]+x[b]<n)
			a++;
		else
			b--;
	}
	cout<<"NO";
				
}