# include <cstdio>
# include <cctype>
# include <cstring>

char inp1[101],inp2[101],inp3[101];
char check[6][301];
char student[601];

void generate(char *i1,char *i2,char *i3,char* out)
{
	strcpy(out,i1);
	strcat(out,i2);
	strcat(out,i3);
}

void modify(char *inp)
{
	int pos=0;
	for(int i=0;inp[i];i++)
		if(isalpha(inp[i]))
			inp[pos++]=tolower(inp[i]);
	inp[pos]=0;
}

int main()
{
	scanf("%s%s%s",inp1,inp2,inp3);

	modify(inp1);
	modify(inp2);
	modify(inp3);
	
	generate(inp1,inp2,inp3,check[0]);
	generate(inp1,inp3,inp2,check[1]);
	generate(inp2,inp1,inp3,check[2]);
	generate(inp2,inp3,inp1,check[3]);
	generate(inp3,inp2,inp1,check[4]);
	generate(inp3,inp1,inp2,check[5]);
	
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		scanf("%s",student);
		modify(student);
		for(int j=0;j<6;j++)
			if(strcmp(student,check[j])==0)
			{
				printf("ACC\n");
				goto bpp;
			}
		printf("WA\n");
		bpp:;
	}
}