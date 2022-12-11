#include<bits/stdc++.h> 
using namespace std;
int k,a,b,t1,t2,s1,s2;
int main()
{
	scanf("%d%d%d",&k,&a,&b);
	t1=a/k;s1=a%k;
	t2=b/k;s2=b%k;
	if(t2==0&&s1)puts("-1");
	else if(t1==0&&s2)puts("-1");
	else printf("%d\n",t1+t2);
}