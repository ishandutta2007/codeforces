#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int v[1010][1010];
int main()
{
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	int md=9999,x,y;
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			if(abs(i-x1)+abs(i-x2)+abs(i-x3)+abs(j-y1)+abs(j-y2)+abs(j-y3)<md)
			{
				md=abs(i-x1)+abs(i-x2)+abs(i-x3)+abs(j-y1)+abs(j-y2)+abs(j-y3);
				x=i;
				y=j;
			}
	cout<<md+1<<endl;
	int nowx=x,nowy=y;
	while(nowx!=x1||nowy!=y1)
	{
		v[nowx][nowy]=1;
		if(nowx>x1)
			nowx--;
		else
			if(nowx<x1)
				nowx++;
			else
				if(nowy>y1)
					nowy--;
				else
					nowy++;
	}
	v[x1][y1]=v[x2][y2]=v[x3][y3]=1;
	nowx=x,nowy=y;
	while(nowx!=x2||nowy!=y2)
	{
		v[nowx][nowy]=1;
		if(nowx>x2)
			nowx--;
		else
			if(nowx<x2)
				nowx++;
			else
				if(nowy>y2)
					nowy--;
				else
					nowy++;
	}
		nowx=x,nowy=y;
	while(nowx!=x3||nowy!=y3)
	{
		v[nowx][nowy]=1;
		if(nowx>x3)
			nowx--;
		else
			if(nowx<x3)
				nowx++;
			else
				if(nowy>y3)
					nowy--;
				else
					nowy++;
	}
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			if(v[i][j])
			{
				printf("%d %d\n",i,j);
			}
}