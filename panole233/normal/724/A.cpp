#include<cstdio>
#include<cstring>

char s1[10],s2[10];
const char s[7][10]={{'m','o','n','d','a','y',0,0,0,0},{'t','u','e','s','d','a','y',0,0,0},
					{'w','e','d','n','e','s','d','a','y',0},{'t','h','u','r','s','d','a','y',0,0},
					{'f','r','i','d','a','y',0,0,0,0},{'s','a','t','u','r','d','a','y',0,0},
					{'s','u','n','d','a','y',0,0,0,0}};
int x,y;

int main()
{
	scanf("%s%s",&s1,&s2);
	for (int i=0; i<7; i++)
		if (strcmp(s1,s[i])==0) {x=i; break;}
	for (int i=0; i<7; i++)
		if (strcmp(s2,s[i])==0) {y=i; break;}
	if (y<x) y+=7;
	if (x==y) printf("YES"); else 
	if (x==y-2) printf("YES"); else
	if (x==y-3) printf("YES"); else
	printf("NO");
	return 0;
}