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
#include<bitset>
using namespace std;
int num[10010];
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		num[i]=t1*60+t2;
	}
	for(int j=0;j<=10000;j++)
	{
		int can=1;
		for(int i=1;i<=n;i++)
		{
			if(abs(j-num[i])<=s)
				can=0;
		}
		if(can)
		{
			cout<<j/60<<' '<<j%60<<endl;
			return 0;
		}
	}
}