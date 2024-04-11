#include <stdio.h>
#include <string.h>

int arr[100010];
char str[100010];

int main() {
	int i,j;
	scanf("%s",str);
	int l = strlen(str);
	char ch = str[l-1];
	arr[l-1] = 1;
	for(i=l-2;i>=0;i--) {
		if(str[i] > ch)
			ch = str[i];
		if(str[i] >= ch)
			arr[i] = 1;
	}
	for(i=0;i<l;i++)
		if(arr[i])
			printf("%c",str[i]);
	return 0;
}