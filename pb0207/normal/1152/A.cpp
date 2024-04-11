#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,m,a[N],b[N],ea,oa,eb,ob;

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),oa+=a[i]&1;
	ea=n-oa;
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),ob+=b[i]&1;
	eb=m-ob;
	printf("%d",min(ob,ea)+min(eb,oa));
}