#include <stdio.h>

int arr[10];
int n;

int check(int a) {
	while(a) {
		if(arr[a%10])
			return 1;
		a /= 10;
	}
	return 0;
}
int main() {
	int i;
	int ans = 0;
	scanf("%d",&n);
	for(i=n;i;i/=10)
		arr[i%10] = 1;
	for(i=1;i*i<=n;i++) {
		if(n%i == 0) {
			if(check(i))
				ans++;
			if(i*i < n && check(n/i))
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}