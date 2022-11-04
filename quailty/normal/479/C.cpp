#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct examination
{
	int a;
	int b;
}exam[5000];
bool comp(examination p,examination q)
{
	if(p.a==q.a)return p.b<q.b;
	else return p.a<q.a;
}
int main()
{
	int n,i,result;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		scanf("%d%d",&exam[i].a,&exam[i].b);
	sort(exam,exam+n,comp);
	result=-1;
	for(i=0;i<=n-1;i++){
		if(result<=exam[i].b)result=exam[i].b;
		else result=exam[i].a;
	}
	printf("%d\n",result);
	return 0;
}