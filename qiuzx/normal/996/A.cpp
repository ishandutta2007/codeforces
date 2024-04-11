#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,num=0,i,x,mon[5]={100,20,10,5,1};
	cin>>n;
	while(n!=0)
	{
		for(i=0;i<5;i++)
		{
			if(n>=mon[i])
			{
				x=n/mon[i];
				num+=x;
				break;
			}
		}
		n-=x*mon[i];
	}
	cout<<num<<endl;
	return 0;
}