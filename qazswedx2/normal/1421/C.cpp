#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	printf("3\nL 2\n");
	printf("R 2\n");
	printf("R %d\n",2*n-1);
	return 0;
}