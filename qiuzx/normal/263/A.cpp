#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,step,x,y;
	char a;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			cin>>a;
			if(a=='1')
			{
				x=i;
				y=j;
			}
		}
	}
	step=abs(x-2)+abs(y-2);
	cout<<step<<endl;
	return 0;
}