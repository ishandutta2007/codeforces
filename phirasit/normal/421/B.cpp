#include <stdio.h>
#include <string.h>

int arr[256];
char str[100010];

int main() {
	scanf("%s",str);
	arr['A'] = arr['H'] = arr['I'] = arr['M'] = arr['T'] = arr['X'] = 1;
	arr['W'] = arr['V'] = arr['Y'] = arr['O'] = arr['U'] = 1;
	bool found = false;
	for(int i=0,j=strlen(str)-1;i <= j;i++,j--) {
		if(!arr[str[i]] || str[i] != str[j]) {
			found = true;
		}
	}
	printf("%s\n",found == true ? "NO" : "YES");
	return 0;
}