#include<bits/stdc++.h>
using namespace std;
int n,k,t,d,ans1,ans2,t1,t2;
int main()
{
	scanf("%d%d%d%d",&n,&t,&k,&d);
	ans1=((n-1)/k+1)*t;
	t2=d;
	for(;t1<t2&&n>0;t1+=t,n-=k);
	for(;n>0;)
	if(n>k)
	{
		t1+=t;
		n-=k;
		t2+=t;
		n-=k;
	}
	else
	{
		if(t1>t2)t2+=t;
		else t1+=t;
		n=0;
	}
	ans2=max(t1,t2);
	if(ans2<ans1)printf("YES");
	else printf("NO");
	return 0;
}