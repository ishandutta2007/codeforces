#include <stdio.h>
#include <string.h>

char str[310];
int k;

int main() {
	scanf("%s%d", str, &k);
	int l = strlen(str);
	int mx = 0;
	for(int i = 1;2*i <= l+k;i++) {
		for(int p = 0;p+2*i <= l+k;p++) {
			bool err = false;
			for(int j = p;j < p+i;j++) {
				if(j+i < l && str[j] != str[j+i]) {
					err = true;
				}
			}
			if(!err && i > mx) {
				mx = i;
			}
		}
	}
	printf("%d\n", 2*mx);
	return 0;
}