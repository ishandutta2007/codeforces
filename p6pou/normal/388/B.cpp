#include<bits/stdc++.h>
using namespace std;
const unsigned int classroom=4274906972ll;
char a[3240][3240];
int sep_result[324],k;
//1-4 Y 3n--3n+1 Y 3n+1--3n+2 Y 3n--3n+4 Y 3n+2--3n+4 Y
int sep_2(int x)
{
	int num=int(log2(x))+1;
	int ans=num;
	while (x!=0)
	{
		sep_result[num]=x%2;
		x/=2;
		num--;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>k;
	int o=sep_2(k);
//	for (int i=1;i<=o;i++)
//	{
//		cout<<sep_result[i];
//	}
	cout<<5*o<<endl;
	for (int i=1;i<=5*o;i++)
	{
		for (int j=1;j<=5*o;j++)
		{
			a[i][j]='N';
		}
	}
	for (int i=1;i<=3*o;i++)
	{
		for (int j=1;j<=3*o+1;j++)
		{
			if (i==1 && j==4)
			{
				a[i][j]='Y';
				a[j][i]='Y';
			}
			else if (i>1)
			{
				if (j==i+1 && i%3==0) 
				{
					a[i][j]='Y';
					a[j][i]='Y';
				}
				if (j==i+2 && i%3==2)
				{
					a[i][j]='Y';
					a[j][i]='Y';
				}
				if (j==i+4 && i%3==0)
				{
					a[i][j]='Y';
					a[j][i]='Y';
				}
				if (j==i+1 && i%3==1)
				{
					a[i][j]='Y';
					a[j][i]='Y';
				}
			}
		}
	}
	a[2][4]='N';
	a[4][2]='N';
	int p=0;
	for (int i=o;i>=1;i--)
	{
		p++;
		if (sep_result[i]==1)
		{
			a[3*p][3*o+2*p]='Y';
			a[3*o+2*p][3*p]='Y';
		}
	}
	a[5*o][2]='Y';
	a[2][5*o]='Y';
	for (int i=3*o+2;i<=5*o;i++)
	{
		a[i][i+1]='Y';
		a[i+1][i]='Y';
	}
	for (int i=1;i<=5*o;i++)
	{
		for (int j=1;j<=5*o;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}