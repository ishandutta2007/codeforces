#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int p[100007];
string im[100007];
string naz[100007];
string tmp;
string pop;
int j;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		cin >> im[i] >> naz[i];
		if (naz[i]<im[i])
		{
			tmp=naz[i];
			naz[i]=im[i];
			im[i]=tmp;
		}
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &p[i]);
	}
	pop=im[p[1]];
	for (int i=2; i<=n; i++)
	{
		j=p[i];
		if (im[j]>=pop)
		{
			pop=im[j];
			continue;
		}
		if (naz[j]>=pop)
		{
			pop=naz[j];
			continue;
		}
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}