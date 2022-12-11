/* Inna and Nine */

#include <stdio.h>
#include <string.h>

#define MX_N 100010
#define LL long long

char str[MX_N];
LL opt[MX_N][2];

int main() {
	int i;
	scanf("%s",str);
	for(i=0;str[i];i++) {
		if(i == 0) {
			opt[i][0] = (str[i] == '9');
			opt[i][1] = 1;
		}else {
			opt[i][0] = opt[i-1][0] + (str[i] == '9');
			opt[i][1] = opt[i-1][1];
			if(i > 0 && (str[i] + str[i-1] == '0'+'0'+9)) {
				if(i == 1) {
					opt[i][0] = 1;
					opt[i][2] = 1;
				}else if(opt[i-2][0] + 1 > opt[i][0]) {
					opt[i][0] = opt[i-2][0] + 1;
					opt[i][1] = opt[i-2][1];
				}else if(opt[i-2][0] + 1 == opt[i][0]) {
					opt[i][1] += opt[i-2][1];
				}
			}
		}
	}
	printf("%I64d\n",opt[strlen(str)-1][1]);
	return 0;
}