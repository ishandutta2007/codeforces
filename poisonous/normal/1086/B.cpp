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
int d[199999];
int main()
{
	int n;
	double m;
	cin>>n>>m;
	if(n==2)
	{
		printf("%.10f\n",m);
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		d[t1]++;
		d[t2]++;
	}
	double x=m*2.0;
	int y=0;
	for(int i=1;i<=n;i++)
		if(d[i]==1)
			y++;
	printf("%.10f\n",x/y);
}