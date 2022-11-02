#include <cstdio>
#include <cstring>
using namespace std;
char st[2000010];
int n;
void work1()
{
	int i=1,num1=0,num2=0;
	for(;'0'<=st[i]&&st[i]<='9';i++)
		num1=num1*10+st[i]-'0';
	i++;
	for(;'0'<=st[i]&&st[i]<='9';i++)
		num2=num2*10+st[i]-'0';
	int p=26;
	for(;num2>p;)
	{
		num2-=p;
		p*=26;
	}
	p/=26;
	for(;p;)
	{
		putchar((num2-1)/p+'A');
		num2=(num2-1)%p+1;
		p/=26;
	}
	printf("%d\n",num1);
}
void work2()
{
	int num1=0,num2=0,i=0;
	for(;'A'<=st[i]&&st[i]<='Z';i++)
		num1=num1*26+st[i]-'A';
	int p=26;
	for(int j=1;j<i;j++)
	{
		num1+=p;
		p*=26;
	}
	for(;'0'<=st[i]&&st[i]<='9';i++)
		num2=num2*10+st[i]-'0';
	printf("R%dC%d\n",num2,num1+1);
}
int main()
{
	scanf("%d\n",&n);
	for(;n--;)
	{
		scanf("%s",st);
		int posR=-1,posC=-1,len=strlen(st);
		for(int i=0;i<len;i++)
		{
			if(st[i]=='R')
				posR=i;
			if(st[i]=='C')
				posC=i;
		}
		if(posR==-1||posC==-1)
			work2();
		else
		{
			int pos=0;
			for(int i=posR+1;i<posC;i++)
				if('0'<=st[i]&&st[i]<='9')
				{
					pos=i;
					break;
				}
			if(pos)
				work1();
			else
				work2();
		}
	}
	return 0;
}