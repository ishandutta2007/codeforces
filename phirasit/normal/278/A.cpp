#include <stdio.h>

int arr[110];
int n,a,b;

int main() {
	int i,j = 0,k;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		j += arr[i];
	}
	scanf("%d %d",&a,&b);
	a--;
	b--;
	if(b < a) {
		i = a;
		a = b;
		b = i;
	}
	k = 0;
	for(i=a;i<b;i++) {
		k += arr[i];
	}
	if(k < j-k) printf("%d\n",k);
	else printf("%d\n",j-k);
	return 0;
}