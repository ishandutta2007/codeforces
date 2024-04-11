#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a,b;

char s[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='-')
			a++;
		else
			b++;
	if(b==0)
		puts("YES");
	else
		puts(a%b==0?"YES":"NO");
}