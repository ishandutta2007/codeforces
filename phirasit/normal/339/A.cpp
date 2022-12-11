#include <stdio.h>

char str[110];
int arr[4];

int main() {
	int i,j;
	scanf("%s",str);
	for(i=1;i<=3;i++)
		arr[i] = 0;
	int a = 0;
	for(i=0;str[i] != 0;i+=2) {
		arr[str[i]-'0']++;
		a++;
	}
	i = 1;
	while(a--) {
		if(arr[i]) {
			printf("%d",i);
			if(a != 0) printf("+");
			arr[i]--;
		}else {
			i++;
			a++;
		}
	}
	return 0;
}