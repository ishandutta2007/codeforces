#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%i",&n);
	int a=1;
	for(int i=1;i<26;i++)
	{
		int x=1<<i;
		//printf("%i %i\n",a,x);
		a+=x;
	}
	int ekses=0;
	for(int i=0;i<n-1;i++)
	{
		//printf("a:%i\n",a);
		char c,lol;
		char niz[100000]={};
		scanf(" %c %s",&c,niz);
		int b=0;
		string s=niz;
		for(int j=0;j<s.length();j++)
		{
			//printf("%c",niz[j]);
			int t=niz[j]-'a';
			int x=1<<t;
			b=b|x;
			//printf(" %i\n",b);
		}
		//printf("\n");
		if(c=='.')
		{
			int c=a&b;
			a=a^c;
		}
		if(c=='!')
		{
			//printf("%i %i\n",a,b);
			if(__builtin_popcount(a)==1)
			{
				ekses++;
			}
			a=a&b;
		}
		if(c=='?')
		{
			if(__builtin_popcount(a)==1)
			{
				ekses++;
			}
			int c=a&b;
			a=a^c;
		}
	}
	char c,c1;
	scanf("%c %c",&c,&c1);
	printf("%i ",ekses);
}