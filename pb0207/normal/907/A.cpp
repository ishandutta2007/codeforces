#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b,c,d;

bool chk(int x,int y,int z)
{
	if(x<a)
		return 0;
	if(x>2*a)
		return 0;
	if(y<b)
		return 0;
	if(y>2*b)
		return 0;
	if(z<c)
		return 0;
	if(z>2*c)
		return 0;
	if(d*2>=x||d*2>=y||d*2<z)
		return 0;
	if(d>z||d>y||d>x)
		return 0;
	return 1;
}

int main()
{
	cin>>a>>b>>c>>d;
	for(int i=1;i<=200;i++)
		for(int j=1;j<i;j++)
			for(int k=1;k<j;k++)
				if(chk(i,j,k))
				{
					cout<<i<<endl<<j<<endl<<k<<endl;
					return 0;
				}
	puts("-1");
}