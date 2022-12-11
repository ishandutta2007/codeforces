#include <stdio.h>
#include <string.h>

char name[10][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char str[10];
int n;

int main() {
	scanf("%d%s", &n, str);
	for(int i = 0;i < 8;i++) {
		if(n != strlen(name[i])) {
			continue;
		}
		bool err = false;
		for(int j = 0;j < n;j++) {
			if(str[j] != '.' && str[j] != name[i][j]) {
				err = true;
			}
		}
		if(!err) {
			printf("%s\n", name[i]);
			break;
		}	
	}
	return 0;
}