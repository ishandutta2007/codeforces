#include<cstdio>
using namespace std;



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,n,S;
		scanf("%d%d%d%d",&a,&b,&n,&S);
		if(1ll*a*n+b<1ll*S)
			puts("No");
		else if(S%n>b)
			puts("No");
		else
			puts("Yes");
	}
}