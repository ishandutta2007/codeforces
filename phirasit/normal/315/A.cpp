#include <stdio.h>

int arr[110][2];
int use[1010];
int n;

int main() {
	int i,ans = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d",&arr[i][0],&arr[i][1]);
		use[arr[i][1]]++;
	}
	for(i=0;i<n;i++) {
		if(arr[i][0] == arr[i][1]) {
			if(use[arr[i][0]]-1 <= 0)
				ans++;
		}else if(use[arr[i][0]] <= 0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}