# include <cstdio>

char inp1[101],inp2[101];

int main()
{
	scanf("%s%s",inp1,inp2);
	for(int i=0;inp1[i];i++)
		if(inp1[i]==inp2[i])
			printf("0");
		else
			printf("1");
	printf("\n");
	return 0;
}