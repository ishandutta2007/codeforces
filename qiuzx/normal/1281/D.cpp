#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 70
using namespace std;
string grid[N];
int n,m;
bool one,two,three,four,cant,zero,t;
int main(){
	int T,i,j;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		one=two=three=four=false;
		cant=zero=true;
		for(i=0;i<n;i++)
		{
			cin>>grid[i];
		}
		for(i=0;i<n;i++)
		{
			if(grid[i].find('P')==-1)
			{
				if(i==0||i==n-1)
				{
					one=true;
				}
				else
				{
					two=true;
				}
			}
			for(j=0;j<m;j++)
			{
				if(grid[i][j]=='A')
				{
					cant=false;
					four=true;
					if((i==0||i==n-1)&&(j==0||j==m-1))
					{
						two=true;
					}
					else if(i==0||i==n-1||j==0||j==m-1)
					{
						three=true; 
					}
				}
				else
				{
					zero=false;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			t=true;
			for(j=0;j<n;j++)
			{
				if(grid[j][i]=='P')
				{
					t=false;
					break;
				}
			}
			if(t)
			{
				if(i==0||i==m-1)
				{
					one=true;
				}
				else
				{
					two=true;
				}
			}
		}
		if(cant)
		{
			cout<<"MORTAL"<<endl; 
		}
		else if(zero)
		{
			cout<<0<<endl;
		}
		else if(one)
		{
			cout<<1<<endl;
		}
		else if(two)
		{
			cout<<2<<endl;
		}
		else if(three)
		{
			cout<<3<<endl;
		}
		else if(four)
		{
			cout<<4<<endl;
		}
	}
	return 0;
}