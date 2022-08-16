# include <cstdio>
# include <cstring>

int N;
char inp[1000001];

void work(int i)
{
	if(inp[i]=='r')printf("%d\n",i+1);
	if(i<N-1)work(i+1);
	if(inp[i]=='l')printf("%d\n",i+1);
}

int main()
{
	scanf("%s",inp);
	N=strlen(inp);
	work(0);
	return 0;
}