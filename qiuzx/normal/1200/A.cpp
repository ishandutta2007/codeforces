#include <bits/stdc++.h>
#define N 12
using namespace std;
bool book[N];
int n;
char c;
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>c;
		if(c=='L')
		{
			for(j=0;j<10;j++)
			{
				if(!book[j])
				{
					book[j]=true;
					break;
				}
			}
		}
		else if(c=='R')
		{
			for(j=9;j>=0;j--)
			{
				if(!book[j])
				{
					book[j]=true;
					break;
				}
			}
		}
		else
		{
			book[c-'0']=false;
		}
	}
	for(i=0;i<10;i++)
	{
		cout<<book[i];
	}
	cout<<endl;
	return 0;
}