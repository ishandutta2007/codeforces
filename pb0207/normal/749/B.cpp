#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

double xa,xb,xc,ya,yb,yc;

int main()
{
	cin>>xa>>ya;
	cin>>xb>>yb;
	cin>>xc>>yc;
	if((yb-ya)*(xc-xb)==(yc-yb)*(xb-xa))
	{
		cout<<0;
		return 0;
	}
	cout<<3<<endl;
	cout<<xc+(xb-xa)<<" "<<yc+(yb-ya)<<endl;
	cout<<xa+(xc-xb)<<" "<<ya+(yc-yb)<<endl;
	cout<<xb+(xa-xc)<<" "<<yb+(ya-yc);
}