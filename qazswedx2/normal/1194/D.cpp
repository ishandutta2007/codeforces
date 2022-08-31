#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k;
void print(int x)
{
	if(x) printf("Alice\n");
	else printf("Bob\n");
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k%3) print(n%3);
		else
		{
			int q=n%(k+1);
			if(q==k) print(3);
			else print(q%3);
		}
	}
	return 0;
}