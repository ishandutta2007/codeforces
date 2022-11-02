#include<cstdio>
#include<algorithm>
using namespace std;
struct number
{
	int a,b,c;
	friend bool operator <(number a,number b){return a.a>b.a;}
}num[100010];
int p[100010],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)num[i].c=i;
	for(int i=1;i<=n;i++)scanf("%d",&num[i].a);
	for(int i=1;i<=n;i++)scanf("%d",&num[i].b);
	sort(num+1,num+n+1);
	p[1]=num[1].c;
	for(int i=1;i<=n/2;i++)p[i+1]=num[2*i].b>num[2*i+1].b?num[2*i].c:num[2*i+1].c;
	printf("%d\n",n/2+1);
	for(int i=1;i<=n/2;i++)printf("%d ",p[i]);
	printf("%d",p[n/2+1]);
	return 0;
}