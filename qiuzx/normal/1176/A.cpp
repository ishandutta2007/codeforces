#include <bits/stdc++.h>
using namespace std;
int main(){
	long long q,n,num;
	bool flag;
	cin>>q;
	while(q--)
	{
		cin>>n;
		num=0;
		flag=true;
		while(n!=1&&flag)
		{
			flag=false;
			if(n%2==0)
			{
				n/=2;
				num++;
				flag=true;
			}
			if(n%3==0)
			{
				n=n*2/3;
				num++;
				flag=true;
			}
			if(n%5==0)
			{
				n=n*4/5;
				num++;
				flag=true;
			}
		}
		if(n!=1)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<num<<endl;
		}
	}
	return 0;
}