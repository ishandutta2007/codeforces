#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[200],b[200],c[300];

int main() {
	int i,j=0;
	scanf("%s %s %s",a,b,c);
	strcat(a,b);
	sort(a,a+strlen(a));
	sort(c,c+strlen(c));
	if(strlen(a) != strlen(c))
		j = 1;
	for(i=0;a[i];i++)
		if(a[i] != c[i])
			break;
	if(a[i]) j = 1;
	if(j == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}