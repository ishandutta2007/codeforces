#include<bits/stdc++.h>
using namespace std;

int T,a,b,c,d;

int main() 
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		cin>>c>>d;
		if(a>b)
			swap(a,b);
		if(c>d)
			swap(c,d);
		if(a==c&&a==b+d)
			puts("Yes");
		else if(b==d&&b==a+c)
			puts("Yes");
		else
			puts("No");
	}
}