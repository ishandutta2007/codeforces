#include <stdio.h>
#include <string.h>

int arr[100010];
char str[100010];

int main() {
	int i,j,t;
	int l;
	scanf("%s",str);
	l = strlen(str);
	for(i=0;i<l;i++) {
		arr[i] = arr[i-1];
		if(str[i] == str[i-1])
			arr[i]++;
	}
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&i,&j);
		printf("%d\n",arr[j-1] - arr[i-1]);
	}
	return 0;
}