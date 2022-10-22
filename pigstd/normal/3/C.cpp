#include<bits/stdc++.h>
using namespace std;

int a[4][4],sum1,sum2;
//2:x 1:0 0:.

bool cg(int k)
{
	for (int i=1;i<=3;i++)
		if ((a[i][1]==k&&a[i][2]==k&&a[i][3]==k)||(a[1][i]==k&&a[2][i]==k&&a[3][i]==k))
			return 1;
	if (a[1][1]==k&&a[2][2]==k&&a[3][3]==k)
		return 1;
	if (a[1][3]==k&&a[2][2]==k&&a[3][1]==k)
		return 1;
	return 0;
}

bool pj()
{
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (!a[i][j])
				return 0;
	return 1;
}

int main()
{
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
		{
			char ch;
			cin>>ch;
			if (ch=='0')sum2++,a[i][j]=1;
			if (ch=='X')sum1++,a[i][j]=2;
		}
	if (sum1-sum2!=1&&sum1-sum2!=0||cg(1)&&cg(2)||(cg(1)&&sum1!=sum2)||(cg(2)&&sum1==sum2))
		{cout<<"illegal";return 0;}
	if (cg(1))
		{cout<<"the second player won";return 0;}
	if (cg(2))
		{cout<<"the first player won";return 0;}
	if (pj())
		{cout<<"draw";return 0;}
	if (sum1==sum2)
		{cout<<"first";return 0;}
	if (sum1-sum2==1)
		{cout<<"second";return 0;}
	return 0;
}