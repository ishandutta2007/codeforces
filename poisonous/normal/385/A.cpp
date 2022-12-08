#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int c[1000];
int main()
{
	int a,b,d;
	cin>>a>>b;
	for(d=1;d<=a;d++)
	{
		cin>>c[d];
	}
	int now=0,ans=0;
	for(d=1;d<a;d++)
	{
		if(c[d]-c[d+1]>now)
			now=c[d]-c[d+1];	
	}
	now-=b;
	if(now>0)
		cout<<now;
	else
		cout<<0;
}