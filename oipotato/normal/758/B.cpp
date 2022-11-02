#include<cstdio>
using namespace std;
int dead[10],pos[10],i;
char st[10010];
int main()
{
	scanf("%s",st);
	for(i=0;st[i];i++)
	if(st[i]=='!')dead[i%4]++;
	else if(st[i]=='R')pos[0]=i%4;
	else if(st[i]=='B')pos[1]=i%4;
	else if(st[i]=='Y')pos[2]=i%4;
	else pos[3]=i%4;
	for(i=0;i<4;i++)printf("%d ",dead[pos[i]]);
	return 0;
}