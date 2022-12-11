#include<bits\stdc++.h>
using namespace std;
char s[101];
int main()
{
	int i,j,k;
	scanf("%s",s);
	int l=strlen(s);
	for(i=0;i<l;i++)if(s[i]>'4'&&(s[i]!='9'||i!=0))putchar('9'-s[i]+'0');else putchar(s[i]);
	puts("");
	return 0;
}