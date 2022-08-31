# include <cstdio>

int main()
{
	int a,b,r;
	scanf("%d%d%d",&a,&b,&r);

	if(a>b)a=b;
	if(a<2*r)printf("Second\n");
	else printf("First\n");

	return 0;
}