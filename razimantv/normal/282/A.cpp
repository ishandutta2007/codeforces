# include <cstdio>

int main()
{
	int N;
	scanf("%d",&N);

	int ret=0;
	for(int i=0;i<N;i++)
	{
		char inp[10];
		scanf("%s",inp);
		if(inp[1]=='+')ret++;
		else ret--;
	}
	printf("%d\n",ret);
	return 0;
}