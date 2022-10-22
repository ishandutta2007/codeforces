#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],cnt[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=n;i++)
		if(cnt[a[i]]&1)
		{
			puts("Conan");
			return 0;
		}
	puts("Agasa");
}