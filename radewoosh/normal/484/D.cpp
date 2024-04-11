#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long war[1000007];
long long wyn[1000007];
int ostg;
int ostd;

bool g(int v)
{
	if (!v || v==n+1)
	return true;
	if ((v==1 || war[v-1]<=war[v]) && (v==n || war[v+1]<=war[v]))
	return true;
	return false;
}

bool d(int v)
{
	if (!v || v==n+1)
	return true;
	if ((v==1 || war[v-1]>=war[v]) && (v==n || war[v+1]>=war[v]))
	return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &war[i]);
	}
	for (int i=1; i<=n; i++)
	{
		if (g(i) || g(i+1))
		{
			wyn[i]=max(wyn[i], wyn[ostd]+(war[i]-war[ostd+1]));
			if (ostd)
			wyn[i]=max(wyn[i], wyn[ostd-1]+(war[i]-war[ostd]));
		}
		if (d(i) || d(i+1))
		{
			wyn[i]=max(wyn[i], wyn[ostg]-(war[i]-war[ostg+1]));
			if (ostg)
			wyn[i]=max(wyn[i], wyn[ostg-1]-(war[i]-war[ostg]));
		}
		if (g(i))
		{
			ostg=i;
		}
		if (d(i))
		{
			ostd=i;
		}
	}
	printf("%lld", wyn[n]);
	return 0;
}