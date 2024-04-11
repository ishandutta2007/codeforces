#include <bits/stdc++.h>
#define N 200010
using namespace std;
long long n,a[N],i,neg=0,zn=0,pos,lt;
bool book[N]={};
int main(){
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	neg=0;
	zn=0;
	pos=-1;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			book[i]=true;
			zn++;
		}
		else if(a[i]<0)
		{
			neg++;
			if(pos==-1)
			{
				pos=i;
			}
			if(a[pos]<a[i])
			{
				pos=i;
			}
		}
	}
	if(neg%2==1)
	{
		book[pos]=1;
	}	
	if(zn==n||(zn==n-1&&neg==1))
	{
		for(i=1;i<n;i++)
		{
			cout<<"1 "<<i<<" "<<i+1<<endl;
		}
		return 0;
	}
	pos=-1;
	for(i=0;i<n;i++)
	{
		if(book[i])
		{
			if(pos!=-1)
			{
				cout<<"1 "<<pos+1<<" "<<i+1<<endl;
			}
			pos=i;
		}
	}
	if(pos!=-1)
	{
		cout<<"2 "<<pos+1<<endl;
	}
	pos=-1;
	for(i=0;i<n;i++)
	{
		if(!book[i])
		{
			if(pos!=-1)
			{
				cout<<"1 "<<pos+1<<" "<<i+1<<endl;
			}
			pos=i;
		}
	}
	return 0;
}