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
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
	int n,x,t1,t2=0;
	cin>>n>>x;
	while(n--)
	{
		scanf("%d",&t1);
		t2+=t1;
	}
	t2=abs(t2);
	if(t2%x==0)
		cout<<t2/x;
	else
		cout<<t2/x+1;
}