#include<iostream>
#include<math.h>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, k, a[55], i, j, b[55], cur;
string s;
char l;
int main()
{
	cin>>n>>k;
	for(i=0; i<=n-k; i++)
	{
		cin>>s;
		if(s=="YES")
		{
			a[i]=1;
		}
		else
		{
			a[i]=0;
		}
	}
	for(i=0; i<k-1; i++)
	{
		b[i]=i;
	}
	cur=k-1;
	for(i=0; i<=n-k; i++)
	{
		if(a[i]==1)
		{
			b[i+k-1]=cur;
			cur++;
		}
		else
		{
			b[i+k-1]=b[i];
		}
	}
	for(i=0; i<n; i++)
	{
		l=b[i]%2+'A';
		cout<<l;
		l=b[i]/2+'a';
		cout<<l;
		cout<<endl;
	}

}