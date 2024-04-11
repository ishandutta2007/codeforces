#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

char s[N][N];

int x,y;

int main()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j+=3)
			scanf("%s",s[i]+j);
	scanf("%d%d",&x,&y);
	x--,y--;
	int tx=x%3,ty=y%3;
	bool flag=false;
	for(int i=tx*3;i<tx*3+3;i++)
		for(int j=ty*3;j<ty*3+3;j++)
			if(s[i][j]=='.')
				flag=true,s[i][j]='!';
	if(flag)
		for(int i=0;i<9;i++,puts(""))
		{
			for(int j=0;j<9;j++)
			{
				putchar(s[i][j]);
				if(j%3==2)
					putchar(' ');		
			}
			if(i%3==2)
				puts("");
		}
	else
		for(int i=0;i<9;i++,puts(""))
		{
			for(int j=0;j<9;j++)
			{
				if(s[i][j]=='.' )
					printf("!");
				else
					putchar(s[i][j]);
				if(j%3==2)
					printf(" ");
			}
			if(i%3==2)
				puts("");
		}
}