#include <stdio.h>

long long arr[100010];
int n;
long long k;

int main() {
	int i,j;
	int a,b,m;
	scanf("%d %I64d",&n,&k);
	for(i=0;i<n;i++) {
		scanf("%I64d",&arr[i]);
		arr[i] += arr[i-1];
	}
	j = 0;
	for(i=0;i<n;i++) {
		a = i;
		b = n-1;
		if(arr[i] - arr[i-1] > k) continue;
		while(a < b) {
			m = (a+b)/2+1;
			if(arr[i-1]+k < arr[m])
				b = m-1;
			else
				a = m;
		}
		if(b-i+1 > j)
			j = b-i+1;
	}
	printf("%d\n",j);
	return 0;
}