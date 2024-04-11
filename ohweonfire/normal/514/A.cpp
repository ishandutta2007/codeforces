#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[55];
	int ls,dir=0,i;
	scanf("%s",s);
	ls=strlen(s);
	if(s[0]=='9')
		dir++;
	for(i=dir;i<ls;i++)
		if(s[i]>'4')
			s[i]='0'+'9'-s[i];
	printf("%s",s);
	return 0;
}