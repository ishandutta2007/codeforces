#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int x,h,m;

bool chk(int a,int b)
{
	return a%10==7||a/10==7||b%10==7||b/10==7; 
}

int main()
{
	cin>>x>>h>>m;
	int ans=0;
	while(!chk(h,m))
	{
		ans++;
		m-=x;
		if(m<0)
		{
			m+=60,h-=1;
			if(h<0)
				h+=24;
		}
	}
	cout<<ans;
}