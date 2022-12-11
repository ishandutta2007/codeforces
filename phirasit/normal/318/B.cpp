#include <stdio.h>

char a[] = "heavy";
char b[] = "metal";
char str[1000010];

int main() {
	int i,j,k;
	long long ans = 0;
	scanf("%s",str);
	for(i=k=0;str[i];i++) {
		for(j=0;j<5;j++)
			if(str[i+j] != a[j])
				break;
		if(j >= 5)
			k++;
		for(j=0;j<5;j++)
			if(str[i+j] != b[j])
				break;
		if(j >= 5)
			ans += k;
	}
	printf("%I64d\n",ans);
	return 0;
}