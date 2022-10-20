#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<a<<"0 "<<a<<"1"<<endl;
	}
	else if(b==a+1)
	{
		cout<<a<<"9 "<<b<<"0"<<endl;
	}
	else if(a==9&&b==1)
	{
		cout<<"99 100"<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}