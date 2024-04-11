#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

char s[1005][1005];
int sz = 0, len[1005], l, max1 = -1, boo = 0;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (gets(s[sz]))
	{
		len[sz] = strlen(s[sz]);
		max1 = max(max1, len[sz]);
		sz++;	
	}
	for (int i = 0; i < max1 + 2; i++)
		printf("*");
	puts("");
	for (int i = 0; i < sz; i++)
	{
		printf("*");
		if (max1 % 2 == len[i] % 2)
		{
			for (int j = 0; j < (max1 - len[i]) / 2; j++)
				printf(" ");
			cout << s[i];
			for (int j = 0; j < (max1 - len[i]) / 2; j++)
				printf(" ");
	   	}
	   	else
	   	{
			for (int j = 0; j < (max1 - len[i]) / 2 + boo; j++)
				printf(" ");
			cout << s[i];
			for (int j = 0; j < (max1 - len[i]) / 2 + 1 - boo; j++)
				printf(" ");	   		
			boo = 1 - boo;
	   	}
		printf("*");
		puts("");
	}
	for (int i = 0; i < max1 + 2; i++)
		printf("*");
	puts("");
	return 0;
}