#include <stdio.h>

int a,b,n;

int main() {
	int i;
	scanf("%d",&n);
	a = b = 0;
	while(n--) {
		scanf("%d",&i);
		if(i == 25) {
			a++;
		}else if(i == 50) {
			if(a == 0)
				break;
			a--;
			b++;
		}else if(i == 100) {
			if(b > 0 && a > 0) {
				b--;
				a--;
			}else if(a >= 3) {
				a -= 3;
			}else {
				break;
			}
		}
	}
	if(n < 0) 	
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}