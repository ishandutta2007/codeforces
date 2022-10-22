#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
ll p,d,ni[120],pt[120];
int main()
{
	ni[1]=9;
	for(int i=2;i<30;i++)ni[i]=ni[i-1]*10+9;
	pt[0]=1;
	for(int i=1;i<30;i++)pt[i]=pt[i-1]*10;
	while(~scanf("%I64d%I64d",&p,&d))
	{
		ll ret=p;
		for(int i=18;i>=0;i--)
		{
			if((p+1)%pt[i]==0)
			break;
			if(p/pt[i]==0)continue;
			ll tmp=(p/pt[i]-1)*pt[i]+ni[i];
			if(tmp<=p&&p-tmp<=d)
			{ret=tmp;break;}
		}
		printf("%I64d\n",ret);
	}
}