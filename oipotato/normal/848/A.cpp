#include <cstdio>
using namespace std;
int main()
{
	int k;
	scanf("%d",&k);
	for(char now='a';now<='z';now++)
	{
		putchar(now);
		if(k==0)
			break;
		int p=1;
		for(;p<=k;)
		{
			putchar(now);
			k-=p;
			p++;
		}
	}
	return 0;
}